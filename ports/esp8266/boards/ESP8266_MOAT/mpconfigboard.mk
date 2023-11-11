LD_FILES = boards/esp8266_2MiB.ld

MICROPY_ESPNOW ?= 1
MICROPY_PY_BTREE ?= 1
MICROPY_VFS_FAT ?= 1
MICROPY_VFS_LFS2 ?= 1

# Add extra packages
FROZEN_MANIFEST ?= $(BOARD_DIR)/manifest.py

# Configure mpconfigboard.h.
CFLAGS += -DMICROPY_ESP8266_2M
