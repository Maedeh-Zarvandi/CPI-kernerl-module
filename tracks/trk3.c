//OS Final Project
//Maedeh Zarvandi - 9425953
//Zahra Talebi - 9328523

#include "../player.h"
#define SONG3_LEN 829971
struct song player_cpi_trk3 = {
	.name = "Interrupt 0x0d",
	.len  = SONG3_LEN,
	.data = {
#include "trk3data.h"
	}
};
