# GEX Firmware for STM32F072

This is the STM32F072 GEX firmware, supporting all STM32F072 GEX boards (including the F072 Discovery).

- [git.ondrovo.com/gex/gex-f072](https://git.ondrovo.com/gex/gex-f072) 
  - upstream repository
- [github.com/gexpander/gex-f072](https://github.com/gexpander/gex-f072) 
  - a GitHub mirror of this repository, accepting issue reports and pull requests
- [github.com/gexpander/gex-core](https://github.com/gexpander/gex-core) 
  - a GitHub mirror of the GexCore submodule

Make sure you clone the repository recursively (`git clone --recursive ...`), or run 
`git submodule update --init` afterwards, to initialize the GexCore submodule.

In order to build the firmware, copy `build.mk.example` to `build.mk`, configure as desired,
and run `make` (see the Make Targets section below). Individual GEX units can be enabled or disabled
in `build.mk`, and the target platform (your GEX board model) is selected here as well.

## Requirements

Listed versions were used during development. Other (particularly newer) versions may work too, 
but without a guarantee. Please submit patches needed to fix incompatibilities, or at least let me 
know.

- **arm-none-eabi-gcc** (v8.1)
- **arm-none-eabi-binutils** (v2.30)
- **arm-none-eabi-newlib** (v3.0)
- **make** (GNU, v4.2)
- **tr** (GNU coreutils 8.29 - but any version should work)
- **dfu-util** (v0.9) for DFU flashing
- **stlink** (texane, v1.5) for ST-Link flashing

## Make Targets

- **make** - basic build (recommended to use with `-j` for faster builds)
- **make flash** - flash using `st-flash`
- **make dfu** - flash using `dfu-convert` and `dfu-util`
- **make clean** - clean files generated during build

All make targets depend on all Makefiles, meaning any modification triggers a full (`-B`) 
rebuild the next time you try to build or flash the firmware.
