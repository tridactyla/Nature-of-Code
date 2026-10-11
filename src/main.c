#include <noc/intro/walker.h>
#include <noc/intro/random-distribution.h>
#include <util/random.h>
#include <stdio.h>

int main() {
  util_random_define_seed();
  printf("Welcome to Nature Of Code codes!\nPlease select your experience:\n[0] Introduction\n");
  int choice = 0;
  printf("Input your choice > ");
  scanf("%i", &choice);
  if(choice == 0) {
    printf("Choose your example:\n[1] Random Walker\n[2] Random Distribution\n[3] Walker Tends to Right\n"); 
  }
  printf("Input your choice > ");
  scanf("%i", &choice);
  if(choice == 1) {
    noc_walker_start(1);
  } else if(choice == 2) {
    noc_random_distribution_start();
  } else if(choice == 3) {
    noc_walker_start(2);
  }
}
