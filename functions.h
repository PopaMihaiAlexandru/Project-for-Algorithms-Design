#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _list{
  int key;
  struct _list* next;
}list;

typedef struct _degree{
  int id;
  int entry;
}degree;


void init_adjacent_list(list* adjacent_list, int vertices);
void init_list(list* lists);
void init_degree(degree* degrees, int vertices);
void entries_adjacent_list(list* adjacent_list, int vertices);
void create_adjacent_list(list* adjacent_list, int value, int index);
void topological_sorting(list* adjacent_list, degree* degree_array, int vertices);

#endif // FUNCTIONS_H_INCLUDED
