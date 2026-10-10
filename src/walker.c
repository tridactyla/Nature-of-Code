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
  int step_x = GetRandomValue(-1, 1);
  int step_y = GetRandomValue(-1, 1);
  walker->x += step_x;
  walker->y += step_y;
}
