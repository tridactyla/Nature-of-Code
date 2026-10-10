#include <util/random.h>
#include <stdlib.h>
#include <time.h>

void util_random_define_seed() {
  srand(time(NULL));
}

int util_random_get_number_by_interval(const int interval) {
  int random_number = rand() % interval;
  return random_number;
}
