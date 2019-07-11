//OS Final Project
//Maedeh Zarvandi - 9425953
//Zahra Talebi - 9328523

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define DEVICE "/dev/player"
int main () {
  int fp,song;
  char cmd,character, buffer_in[6], buffer_out[6];

  fp=open(DEVICE,O_RDWR);
  if(fp == -1){
    printf("File %s does NOT EXIST or LOCKED by other process\n", DEVICE);
    exit(-1);
}

  printf("From wich song you want to start playing ?\n");
  scanf("%d\n",&song);
  sprintf(buffer_in,%d,song);
  write(fp, buffer_in, sizeof(buffer_in));


  close(file);
  return 0;
}
