# Test simple HTTP request with uasyncio.open_connection()

try:
    import uasyncio as asyncio
except ImportError:
    try:
        import asyncio
    except ImportError:
        print("SKIP")
        raise SystemExit


async def http_get(url):
    reader, writer = await asyncio.open_connection(url, 80)

    print("write GET")
    await writer.write(b"GET / HTTP/1.0\r\n\r\n")

    print("read response")
    data = await reader.read(100)
    print("read:", data.split(b"\r\n")[0])

    print("close")
    writer.close()
    await writer.wait_closed()
    print("done")


asyncio.run(http_get("micropython.org"))
