#include <graphics/core.h>
#include <raylib.h>

void graphics_core_setup_with_window(const window_type_t *window) {
  InitWindow(window->width, window->height, window->title);
  SetTargetFPS(60);
}

bool graphics_core_handle_window() {
  return !WindowShouldClose();
}

void graphics_core_draw_begin(const bool should_clear) {
  BeginDrawing();
  if(should_clear) ClearBackground(RAYWHITE);
}

void graphics_core_draw_end() {
  EndDrawing();
}

void graphics_core_terminate() {
  CloseWindow();  
}
