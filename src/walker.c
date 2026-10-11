#include <noc/introduction/walker.h>
#include <graphics/core.h>
#include <util/random.h>
#include <graphics/point.h>
#include <stdlib.h>
#include <raylib.h>

static window_type_t get_window() {
  window_type_t window = { 800, 450, "Random Walker" };
  return window;
}

static walker_type_t walker_create(const int x, const int y) {
  walker_type_t walker = { .x = x/2, .y = y/2 };
  return walker;
}

static void walker_display(walker_type_t *walker) {
  Color color = {
    .r = util_random_get_number_by_interval(254),
    .g = util_random_get_number_by_interval(254),
    .b = util_random_get_number_by_interval(254),
    .a = 255,
  };
  graphics_point_insert_with_color(walker->x, walker->y, color); 
}

static void walker_step(walker_type_t *walker) {
  int step_x = GetRandomValue(-1, 1);
  int step_y = GetRandomValue(-1, 1);
  walker->x += step_x;
  walker->y += step_y;
}

void noc_walker_start() {
  window_type_t window = get_window();
  graphics_core_setup_with_window(&window);
  
  walker_type_t walker = walker_create(window.width, window.height);

  while(graphics_core_handle_window()) {
    graphics_core_draw_begin();
    
    walker_display(&walker);
    walker_step(&walker);

    graphics_core_draw_end();
  }
}
