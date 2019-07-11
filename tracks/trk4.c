//OS Final Project
//Maedeh Zarvandi - 9425953
//Zahra Talebi - 9328523

#include "../player.h"
#define SONG4_LEN 10788741
struct song player_cpi_trk4 = {
	.name = "netcat",
	.len  = SONG4_LEN,
	.data = {
#include "trk4data.h"
	}
};
