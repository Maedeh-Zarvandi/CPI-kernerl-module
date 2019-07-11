//OS Final Project
//Maedeh Zarvandi - 9425953
//Zahra Talebi - 9328523

#include "../player.h"
#define SONG1_LEN 624344
struct song player_cpi_trk1 = {
	.name = "Interrupt 0x7f",
	.len  = SONG1_LEN,
	.data = {
#include "trk1data.h"
	}
};
