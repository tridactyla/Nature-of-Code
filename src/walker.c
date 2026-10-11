#include <noc/intro/walker.h>
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

static void walker_random(walker_type_t *walker) {
    walker_display(walker);
    walker_step(walker);
}

static void walker_step_tend_to_right(walker_type_t *walker) {
  int choice = util_random_get_number_by_interval(10);
  if(choice < 4) {
    walker->x++;
  } else if(choice < 6) {
    walker->x--;
  } else if(choice < 8) {
    walker->y++;
  } else {
    walker->y--;
  }
}

static void walker_tends_to_right(walker_type_t *walker) {
  walker_display(walker);
  walker_step_tend_to_right(walker);
}

static void walker_step_tends_to_mouse(walker_type_t *walker) {
  Vector2 mouse = GetMousePosition();
  int choice = util_random_get_number_by_interval(20);
  if(choice < 10) {
    if(walker->x < mouse.x) {
      walker->x++;
    } else {
      walker->x--;
    }
    if(walker->y < mouse.y) {
      walker->y++;
    } else {
      walker->y--;
    }
  } else if(choice < 12) {
    walker->x++;
  } else if(choice < 14) {
    walker->x--;
  } else if(choice < 17) {
    walker->y++;
  } else if(choice < 20) {
    walker->y--;
  }
}

static void walker_tends_to_mouse(walker_type_t *walker) {
  walker_display(walker);
  walker_step_tends_to_mouse(walker);
}

void noc_walker_start(const int walker_type) {
  window_type_t window = get_window();
  graphics_core_setup_with_window(&window);
  
  walker_type_t walker = walker_create(window.width, window.height);

  while(graphics_core_handle_window()) {
    graphics_core_draw_begin(false);
    
    if(walker_type == 1) walker_random(&walker);
    if(walker_type == 2) walker_tends_to_right(&walker);
    if(walker_type == 3) walker_tends_to_mouse(&walker);

    graphics_core_draw_end();
  }
  
  graphics_core_terminate();
}
