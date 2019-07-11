//OS Final Project
//Maedeh Zarvandi - 9425953
//Zahra Talebi - 9328523

#include "../player.h"
#define SONG2_LEN 11659615
struct song player_cpi_trk2 = {
	.name = "The Internet is an Apt Motherfucker",
	.len  = SONG2_LEN,
	.data = {
#include "trk2data.h"
	}
};
