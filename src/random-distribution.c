#include <noc/introduction/random-distribution.h>
#include <graphics/core.h>

static window_type_t get_window() {
  window_type_t window = { 850, 400, "Random Distribution" };
  return window;
}

void noc_random_distribution_start() {
  window_type_t window = get_window();
  graphics_core_setup_with_window(&window); 

  while(graphics_core_handle_window()) {
    graphics_core_draw_begin();

    graphics_core_draw_end();
  }

}
