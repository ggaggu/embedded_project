#is a simple Makefile
CC	 := arm-none-linux-gnueabi-gcc
KDIR	 := /nfsroot
PWD	 := $(shell pwd)
	
christmas: testrealfinal.c
	gcc -o christmas testrealfinal.c
clean :
	rm -rf *.ko
	rm -rf *.mod.*
	rm -rf *.o                              

