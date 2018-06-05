#include "functions.h"


void init_adjacent_list(list* adjacent_list, int vertices){
  int i;
  for(i = 0; i < vertices; i++){
    adjacent_list[i].key= (int)NULL;
    adjacent_list[i].next = NULL;
  }
}


void init_list(list* lists){
  lists->key= (int)NULL;
  lists->next = NULL;
}

void init_degree(degree* degrees, int vertices){
  int i;
  for(i = 0; i < vertices; i++){
    degrees[i].id = 0;
    degrees[i].entry = 0;
  }
}


void entries_adjacent_list(list* adjacent_list, int vertices){
  char temp[100];
  char* ptr;
  int counter = 0, value;

  while(counter < vertices){

     puts ("Enter the vertex and their respective edges, if the vertex has (Data must be typed with spaces).");
     if (counter == 0) {
       puts ("Examples of how to enter the data:");
       puts ("Example 1 (vertex 5 has the edges 4 and 3): 5 4 3");
       puts ("Example 2 (vertex 6 has no edges): 6");
     }


    fgets(temp, 100, stdin);
    if(temp[(int)(strlen(temp)-1)] == '\n'){
      temp[(int)(strlen(temp)-1)]= '\0';
    }

    adjacent_list[counter].key = (int)strtol(temp, &ptr, 10);

    while(strlen(ptr) != 0){
      value  = (int)strtol(ptr, &ptr, 0);
      create_adjacent_list(adjacent_list, value, counter);
    }

    counter++;
  }
}


void create_adjacent_list(list* adjacent_list, int value, int index){
  list* new_list;
  list* pt_list;

  new_list = (list*)malloc(sizeof(list));
  pt_list = (list*)malloc(sizeof(list));

  if(!pt_list || !new_list){
    puts("Allocation error in memory.");
    exit(0);
  }

  init_list(new_list);
  new_list->key = value;
  pt_list = &adjacent_list[index];

  if(pt_list->next == NULL)
  pt_list->next = new_list;

  else{
    while(pt_list->next != NULL){
      pt_list = pt_list->next;
    }
    pt_list->next = new_list;
  }
}


void topological_sorting(list* adjacent_list, degree* degree_array, int vertices){
  int i, j, k, u;
  int index;
  int ordered[vertices];
  int keep_zeros[vertices];
  int counter = 0;
  list* pt_list;
  pt_list = (list*)malloc(sizeof(list));

  if(!pt_list){
    puts("Allocation error in memory");
    exit(0);
  }

  for(i = 0; i < vertices; i++){
    degree_array[i].id = adjacent_list[i].key;
  }

  for(u = 0; u < vertices; u++){
    keep_zeros[u] = 0;
  }


  for(i = 0; i < vertices; i++){
    pt_list = &adjacent_list[i];
    pt_list = pt_list->next;

    while(pt_list != NULL){
      index = pt_list->key;
      for(j = 0; j < vertices; j++){
        if(degree_array[j].id == index){
          degree_array[j].entry = degree_array[j].entry + 1;
        }
      }
      pt_list = pt_list->next;
    }
  }

  index = 0;


  for(i = 0; i < vertices; i++){
    ordered[i] = (int)NULL;
  }

  while(counter < vertices){


    for(i = 0; i < vertices; i++){
      if(degree_array[i].entry == 0){
        degree_array[i].entry = -1;
        counter = counter + 1;
        keep_zeros[index] = degree_array[i].id;
        index++;
        for(j = 0; j < vertices; j++){
          if(ordered[j] == 0){
            ordered[j] = degree_array[i].id;
            break;
          }
        }
      }
    }

    for(i = 0; i < vertices; i++){
      if(keep_zeros[i] != 0){
        for(j = 0; j < vertices; j++){
          if(adjacent_list[j].key == keep_zeros[i]){
            pt_list = &adjacent_list[j];
            pt_list = pt_list->next;
            while(pt_list != NULL){
              for(k = 0; k < vertices; k++){
                if (degree_array[k].id == pt_list->key){
                  degree_array[k].entry = degree_array[k].entry - 1;
                }
              }
              pt_list = pt_list->next;
            }
          }
        }
      }
    }

    for(i = 0; i < vertices; i++){
      keep_zeros[i] = 0;
    }
  }

  puts("");
  for(i = 0; i < vertices; i++){
    printf("%d ", ordered[i]);
  }

}

