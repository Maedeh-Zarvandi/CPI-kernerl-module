//OS Final Project
//Maedeh Zarvandi - 9425953
//Zahra Talebi - 9328523

#include "../player.h"
#define SONG5_LEN 858054
struct song player_cpi_trk5 = {
	.name = "Interrupt 0xbb",
	.len  = SONG5_LEN,
	.data = {
#include "trk5data.h"
	}
};
