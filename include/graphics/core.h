#ifndef GRAPHICS_CORE_H
#define GRAPHICS_CORE_H

typedef struct window_type_t {
  int width;
  int height;
  char title[128];
} window_type_t;

void graphics_core_setup_with_window(const window_type_t *window);
bool graphics_core_handle_window();
void graphics_core_draw_begin(const bool should_clear);
void graphics_core_draw_end();
void graphics_core_terminate();

#endif // GRAPHICS_CORE_H
