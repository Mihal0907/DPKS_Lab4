ifneq ($(KERNELRELEASE),)
# kbuild part of makefile
ccflags-y += -I$(PWD)/inc
obj-m   := hello.o hello1.o hello2.o
else
# normal makefile
KDIR ?= /lib/modules/`uname -r`/build

default:
	$(MAKE) -C $(KDIR) M=$$PWD
clean:
	$(MAKE) -C $(KDIR) M=$$PWD clean
endif
