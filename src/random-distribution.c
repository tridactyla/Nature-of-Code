#include <noc/intro/random-distribution.h>
#include <util/random.h>
#include <graphics/core.h>
#include <raylib.h>

static window_type_t get_window() {
  window_type_t window = { 850, 400, "Random Distribution" };
  return window;
}

void noc_random_distribution_start() {
  window_type_t window = get_window();
  graphics_core_setup_with_window(&window); 

  int random_counts[20] = {0};
  while(graphics_core_handle_window()) {
    int index = util_random_get_number_by_interval(20);
    random_counts[index]++;
    int w = window.width / 20;

    graphics_core_draw_begin(true);

    for(int x = 0; x < 20; x++) {
      DrawRectangle(x*w, window.height-random_counts[x], w-1, random_counts[x], BLACK);
    }

    graphics_core_draw_end();
  }

}
