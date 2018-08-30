#!/bin/sh

# ----------------------------------------------------------------
# This script invokes openocd as the dbg server using pipe
#
# Author: liuzikai
# Date: Aug 6 2018
#
# NOTICE: Please change the following directory to the absolute path of the project root BEFORE using this script.
# ----------------------------------------------------------------

cd /Users/liuzikai/Documents/RoboMaster/STM32_Explorer
openocd -l openocd.log -c "gdb_port pipe" -f config/STM32_Explorer.cfg
