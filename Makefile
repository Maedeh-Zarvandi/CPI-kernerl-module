#OS Final Project
#Maedeh Zarvandi - 9425953
#Zahra Talebi - 9328523
obj-m += player.o
player-y = player_main.o
player-y+= tracks/trk1.o
player-y+= tracks/trk2.o
player-y+= tracks/trk3.o
player-y+= tracks/trk4.o
player-y+= tracks/trk5.o
player-y+= tracks/trk6.o

KERNELDIR	?=  /lib/modules/$(shell uname -r)/build
PWD		:= $(shell pwd)

all:
	$(MAKE) -C $(KERNELDIR) M=$(PWD)

clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean
