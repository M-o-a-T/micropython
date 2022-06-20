# MicroPython uasyncio module
# MIT license; Copyright (c) 2019-2020 Damien P. George

from . import core


class Stream:
    def __init__(self, s, e={}):
        self.s = s
        self.e = e

    def get_extra_info(self, v):
        return self.e[v]

    async def __aenter__(self):
        return self

    async def __aexit__(self, exc_type, exc, tb):
        self.s.close()
        pass

    def close(self):
        pass

    async def wait_closed(self):
        # TODO yield?
        self.s.close()

    async def read(self, n):
        yield core._io_queue.queue_read(self.s)
        return self.s.read(n)

    async def readinto(self, buf):
        yield core._io_queue.queue_read(self.s)
        return self.s.readinto(buf)

    async def readexactly(self, n):
        r = b""
        while n:
            yield core._io_queue.queue_read(self.s)
            r2 = self.s.read(n)
            if r2 is not None:
                if not len(r2):
                    raise EOFError
                r += r2
                n -= len(r2)
        return r

    async def readline(self):
        l = b""
        while True:
            yield core._io_queue.queue_read(self.s)
            l2 = self.s.readline()  # may do multiple reads but won't block
            l += l2
            if not l2 or l[-1] == 10:  # \n (check l in case l2 is str)
                return l

    async def write(self, buf):
        mv = memoryview(buf)
        off = 0
        while off < len(mv):
            yield core._io_queue.queue_write(self.s)
            ret = self.s.write(mv[off:])
            if ret is not None:
                off += ret


# Stream can be used for both reading and writing to save code size
StreamReader = Stream
StreamWriter = Stream


# Create a TCP stream connection to a remote host
async def open_connection(host, port):
    from uerrno import EINPROGRESS
    import usocket as socket

    ai = socket.getaddrinfo(host, port, 0, socket.SOCK_STREAM)[0]  # TODO this is blocking!
    s = socket.socket(ai[0], ai[1], ai[2])
    s.setblocking(False)
    ss = Stream(s)
    try:
        s.connect(ai[-1])
    except OSError as er:
        if er.errno != EINPROGRESS:
            raise er
    yield core._io_queue.queue_write(s)
    return ss, ss


# Class representing a TCP stream server, can be closed and used in "async with"
class Server:
    async def __aenter__(self):
        return self

    async def __aexit__(self, exc_type, exc, tb):
        self.close()
        await self.wait_closed()

    def close(self):
        self.task.cancel()

    async def wait_closed(self):
        await self.task

    async def _serve(self, s, cb):
        # Accept incoming connections
        while True:
            try:
                yield core._io_queue.queue_read(s)
            except core.CancelledError:
                # Shutdown server
                s.close()
                return
            try:
                s2, addr = s.accept()
            except:
                # Ignore a failed accept
                continue
            s2.setblocking(False)
            s2s = Stream(s2, {"peername": addr})
            core.create_task(cb(s2s, s2s))


# Helper function to start a TCP stream server, running as a new task
# DOES NOT USE TASKGROUPS. Use run_server instead
async def start_server(cb, host, port, backlog=5):
    import usocket as socket

    # Create and bind server socket.
    host = socket.getaddrinfo(host, port)[0]  # TODO this is blocking!
    s = socket.socket()
    s.setblocking(False)
    s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    s.bind(host[-1])
    s.listen(backlog)

    # Create and return server object and task.
    srv = Server()
    srv.task = core.create_task(srv._serve(s, cb))
    return srv


# Helper task to run a TCP stream server
# Callbacks may run in a different taskgroup
async def run_server(cb, host, port, backlog=5, taskgroup=None):
    import usocket as socket

    # Create and bind server socket.
    host = socket.getaddrinfo(host, port)[0]  # TODO this is blocking!
    s = socket.socket()
    s.setblocking(False)
    s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    s.bind(host[-1])
    s.listen(backlog)

    if taskgroup is None:
        async with TaskGroup() as tg:
            await _run_server(tg,s,cb)
    else:
        await _run_server(taskgroup,s,cb)

async def _run_server(tg,s,cb):
    while True:
        try:
            yield core._io_queue.queue_read(s)
        except core.CancelledError:
            # Shutdown server
            s.close()
            return
        try:
            s2, addr = s.accept()
        except Exception:
            # Ignore a failed accept
            continue

        s2.setblocking(False)
        s2s = Stream(s2, {"peername": addr})
        tg.create_task(cb(s2s, s2s))



################################################################################
# Legacy uasyncio compatibility


async def stream_awrite(self, buf, off=0, sz=-1):
    if off != 0 or sz != -1:
        buf = memoryview(buf)
        if sz == -1:
            sz = len(buf)
        buf = buf[off : off + sz]
    await self.write(buf)


Stream.aclose = Stream.wait_closed
Stream.awrite = stream_awrite
Stream.awritestr = stream_awrite  # TODO explicitly convert to bytes?
