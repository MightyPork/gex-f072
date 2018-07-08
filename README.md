# GEX Firmware for STM32F072

This is the STM32F072 GEX firmware, supporting all STM32F072 GEX boards (including the F072 Discovery).

## Links

GEX repositories are mirrored on GitHub to make it easier to submit issues and propose improvements
via "pull requests". **Please use the upstream repository** when cloning to ensure you have the latest 
version of the code. The mirrors are kept up-to-date, but they may fall behind.

- [git.ondrovo.com/gex/gex-f072](https://git.ondrovo.com/gex/gex-f072) - upstream (F072)
- [git.ondrovo.com/gex/gex-core](https://git.ondrovo.com/gex/gex-f072) - upstream (GexCore submodule)
- [github.com/gexpander/gex-f072](https://github.com/gexpander/gex-f072) - GitHub mirror (F072)
- [github.com/gexpander/gex-core](https://github.com/gexpander/gex-core) - GitHub mirror (GexCore submodule)

## Building the Firmware

Make sure you clone the repository recursively (`git clone --recursive ...`), or run 
`git submodule update --init` afterwards, to initialize the GexCore submodule.

In order to build the firmware, first copy the configuration file template `build.mk.example` to 
`build.mk`, modify as desired, then run `make` to build the binary image (see the Make Targets 
section below for more options). 

Individual GEX units can be enabled or disabled in `build.mk`, and the target platform (your GEX 
board model) is selected here as well. The config file is excluded from version control.

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
