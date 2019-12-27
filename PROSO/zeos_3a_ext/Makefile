################################
##############ZeOS #############
################################
########## Makefile ############
################################

# package dev86 is required
AS86	= as86 -0 -a
LD86	= ld86 -0

HOSTCFLAGS = -Wall -Wstrict-prototypes
HOSTCC 	= gcc
CC      = gcc 
AS      = as
LD      = ld
OBJCOPY = objcopy -O binary -R .note -R .comment -S

INCLUDEDIR = include

# Define here flags to compile the tests if needed
JP = 

CFLAGS = -O2  -g $(JP) -ffreestanding -Wall -I$(INCLUDEDIR) 
ASMFLAGS = -I$(INCLUDEDIR)
SYSLDFLAGS = -T system.lds
USRLDFLAGS = -T user.lds
LINKFLAGS = -g 

SYSOBJ = interrupt.o entry.o io.o sys.o sched.o mm.o devices.o utils.o hardware.o fat.o payload.o

#add to USROBJ the object files required to complete the user program
USROBJ = libc.o string.o libjp.a libc_asm.o

all:zeos.bin

zeos.bin: bootsect system build user
	$(OBJCOPY) system system.out
	$(OBJCOPY) user user.out
	./build bootsect system.out user.out > zeos.bin

build: build.c
	$(HOSTCC) $(HOSTCFLAGS) -o $@ $<

bootsect: bootsect.o
	$(LD86) -s -o $@ $<

bootsect.o: bootsect.s
	$(AS86) -o $@ $<

bootsect.s: bootsect.S Makefile
	$(CPP) $(ASMFLAGS) -traditional $< -o $@

entry.s: entry.S $(INCLUDEDIR)/asm.h $(INCLUDEDIR)/segment.h
	$(CPP) $(ASMFLAGS) -o $@ $<

payload.s: payload.S $(INCLUDEDIR)/asm.h $(INCLUDEDIR)/segment.h
	$(CPP) $(ASMFLAGS) -o $@ $<

user.o:user.c $(INCLUDEDIR)/libc.h

string.o:string.c $(INCLUDEDIR)/libc.h

interrupt.o:interrupt.c $(INCLUDEDIR)/interrupt.h $(INCLUDEDIR)/segment.h $(INCLUDEDIR)/types.h

io.o:io.c $(INCLUDEDIR)/io.h

fat.o:fat.c $(INCLUDEDIR)/fat.h

libc.o:libc.c $(INCLUDEDIR)/libc.h

libc_asm.s: libc_asm.S $(INCLUDEDIR)/libc.h
	$(CPP) $(ASMFLAGS) -o $@ $<

mm.o:mm.c $(INCLUDEDIR)/types.h $(INCLUDEDIR)/mm.h

sched.o:sched.c $(INCLUDEDIR)/sched.h

sys.o:sys.c $(INCLUDEDIR)/devices.h

utils.o:utils.c $(INCLUDEDIR)/utils.h


system.o:system.c $(INCLUDEDIR)/hardware.h system.lds $(SYSOBJ) $(INCLUDEDIR)/segment.h $(INCLUDEDIR)/types.h $(INCLUDEDIR)/interrupt.h $(INCLUDEDIR)/system.h $(INCLUDEDIR)/sched.h $(INCLUDEDIR)/mm.h $(INCLUDEDIR)/io.h $(INCLUDEDIR)/mm_address.h 


system: system.o system.lds $(SYSOBJ)
	$(LD) $(LINKFLAGS) $(SYSLDFLAGS) -o $@ $< $(SYSOBJ) 

user: user.o user.lds $(USROBJ) 
	$(LD) $(LINKFLAGS) $(USRLDFLAGS) -o $@ $< $(USROBJ)


clean:
	rm -f *.o *.s bochsout.txt parport.out system.out system bootsect zeos.bin user user.out *~ build

disk: zeos.bin
	dd if=zeos.bin of=/dev/fd0

emul: zeos.bin
	bochs -q -f .bochsrc

emuldbg: zeos.bin
	bochs_nogdb -q -f .bochsrc

jp:	jp1 jp2 jpopen jpread jpwrite jpclose jpopen jpdup jpunlink

jp1:
	ln -f -s libjp1.a libjp.a
	rm -f user zeos.bin
	make
	- bochs -q

jp2:
	ln -f -s libjp2.a libjp.a
	rm -f user zeos.bin
	- make
	- bochs -q
	
jpopen:
	ln -f -s libjpopen.a libjp.a
	rm -f user zeos.bin
	make
	- bochs -q

jpclose:
	ln -f -s libjpclose.a libjp.a
	rm -f user zeos.bin
	make
	- bochs -q

jpread:
	ln -f -s libjpread.a libjp.a
	rm -f user zeos.bin
	make
	- bochs -q

jpwrite:
	ln -f -s libjpwrite.a libjp.a
	rm -f user zeos.bin
	make
	- bochs -q

jpdup:
	ln -f -s libjpdup.a libjp.a
	rm -f user zeos.bin
	make
	- bochs -q

jpunlink:
	ln -f -s libjpunlink.a libjp.a
	rm -f user zeos.bin
	make
	- bochs -q

