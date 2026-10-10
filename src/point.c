#include <graphics/point.h>
#include <raylib.h>

void graphics_point_insert_with_color(const int x, const int y, const Color color) {
  DrawRectangle(x, y, 10, 10, color);
}
