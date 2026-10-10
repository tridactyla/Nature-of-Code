#include <graphics/core.h>
#include <graphics/point.h>
#include <noc/introduction/walker.h>
#include <raylib.h>
#include <util/random.h>

int main() {
  util_random_define_seed();
  window_type_t window = noc_walker_get_window();
  graphics_core_setup_with_window(&window);
  
  walker_type_t walker = noc_walker_create(window.width, window.height);

  while(graphics_core_handle_window()) {
    graphics_core_draw_begin();
    
    noc_walker_display(&walker);
    noc_walker_step(&walker);

    graphics_core_draw_end();
  }
}
