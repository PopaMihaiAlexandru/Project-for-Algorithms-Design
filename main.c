#include "functions.h"

int main(int argc, char *argv[])
{

  list* adjacent_list;
  degree* degree_array;
  int vertices, edges;

  puts ("Enter the number of vertices and edges.");

  scanf("%d %d", &vertices, &edges);
  do{} while (getchar() != '\n');

  adjacent_list = (list*)malloc(sizeof(list)*vertices);
  degree_array = (degree*)malloc(sizeof(degree)*vertices);

  if(!adjacent_list || !degree_array){
    puts("Allocation error");
    exit(0);
  }

  init_adjacent_list(adjacent_list, vertices);
  init_degree(degree_array, vertices);
  entries_adjacent_list(adjacent_list, vertices);
  topological_sorting(adjacent_list, degree_array, vertices);

  free(adjacent_list);
  free(degree_array);
  return 0;
}
