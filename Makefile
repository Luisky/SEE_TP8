# From: linuxdevcenter.com

# Buildroot output path (change this to suit your configuration)
BR_OUTPUT := /home/luisky/cours/M2_LSE/SEE/TP/TP5-9/buildroot/output/

# Cross compiler location
GCC_CROSS := $(BR_OUTPUT)host/usr/bin/arm-linux-gnueabihf-gcc

# default is the default make target.  The rule here says to run make
# with a working directory of the directory containing the kernel
# source and compile only the modules in the PWD (local) directory.
default:
	mkdir -p xbuild
	$(GCC_CROSS) -o xbuild/data_harvester src/main.c

.PHONY: clean
clean:
	$(RM) -rf xbuild/*