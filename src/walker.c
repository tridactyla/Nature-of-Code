#include <noc/introduction/walker.h>
#include <graphics/core.h>
#include <util/random.h>
#include <graphics/point.h>
#include <stdlib.h>
#include <raylib.h>

window_type_t noc_walker_get_window() {
  window_type_t window = { 800, 450, "Random Walker" };
  return window;
}

walker_type_t noc_walker_create(const int x, const int y) {
  walker_type_t walker = { .x = x/2, .y = y/2 };
  return walker;
}

void noc_walker_display(walker_type_t *walker) {
  Color color = {
    .r = util_random_get_number_by_interval(254),
    .g = util_random_get_number_by_interval(254),
    .b = util_random_get_number_by_interval(254),
    .a = 255,
  };
  graphics_point_insert_with_color(walker->x, walker->y, color); 
}

void noc_walker_step(walker_type_t *walker) {
  int choice = util_random_get_number_by_interval(4);

  switch(choice) {
    case 0:
      walker->x++;
      break;
    case 1:
      walker->x--;
      break;
    case 2:
      walker->y++;
      break;
    default:
      walker->y--;
      break;
  }
}
