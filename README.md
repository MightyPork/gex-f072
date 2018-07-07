# GEX Firmware for STM32F072

Copy `build.mk.example` to `build.mk`, configure as desired,
and build the firmware image with `make`.

Individual GEX units can be enabled or disabled in this config file, and the target platform is selected here as well.

## Requirements

Listed versions were used during development. Other (particularly newer) versions may work too, but without guarantee. 
Please submit patches needed to fix incompatibilities, or at least let me know.

- **arm-none-eabi-gcc** (v8.1)
- **arm-none-eabi-binutils** (v2.30)
- **arm-none-eabi-newlib** (v3.0)
- **make** (GNU, v4.2)
- **tr** (GNU coreutils 8.29 - but any version should work)
- **dfu-util** (v0.9) for DFU flashing
- **stlink** (texane, v1.5) for ST-Link flashing

## Make Targets

- **make** - basic build (recommended to use with `-j4` for faster builds)
- **make flash** - flash using `st-flash`
- **make dfu** - flash using `dfu-convert` and `dfu-util`
- **make clean** - clean files generated during build

All make targets depend on all Makefiles, meaning any modification triggers a full (`-B`) 
rebuild the next time you try to build or flash the firmware.
