# Common files and directories
DEV_COMMON_CSRC =
DEV_COMMON_CPPSRC = $(CHIBIOS)/dev/main.cpp \
	                $(CHIBIOS)/dev/led.cpp
DEV_COMMON_INC =

# Rules
ALLCSRC += $(DEV_COMMON_CSRC)
ALLCPPSRC += $(DEV_COMMON_CPPSRC)
ALLINC  += $(DEV_COMMON_INC)