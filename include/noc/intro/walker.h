#ifndef NOC_INTRODUCTION_WALKER_H
#define NOC_INTRODUCTION_WALKER_H

typedef struct walker_type_t {
  int x;
  int y;
} walker_type_t;

void noc_walker_start(const int walker_type);

#endif // NOC_INTRODUCTION_WALK_H
