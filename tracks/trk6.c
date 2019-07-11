//OS Final Project
//Maedeh Zarvandi - 9425953
//Zahra Talebi - 9328523

#include "../player.h"
#define SONG6_LEN 13025371
struct song player_cpi_trk1 = {
	.name = "Approximating the Circumference of the Earth",
	.len  = SONG6_LEN,
	.data = {
#include "trk6data.h"
	}
};
