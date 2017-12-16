target remote | openocd -f openocd.cfg -f gdb-pipe.cfg
monitor halt
monitor gdb_sync
stepi
