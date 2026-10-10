#ifndef NOC_INTRODUCTION_WALKER_H
#define NOC_INTRODUCTION_WALKER_H

#include <graphics/core.h>

typedef struct walker_type_t {
  int x;
  int y;
} walker_type_t;

walker_type_t noc_walker_create(const int x, const int y);
void noc_walker_display(walker_type_t *walker);
void noc_walker_step(walker_type_t *walker);
window_type_t noc_walker_get_window();

#endif // NOC_INTRODUCTION_WALK_H
