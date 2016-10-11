#include <stdlib.h>
#include <stdio.h>

struct node {int i; struct node *next; };


void print_list(struct node *n) {
  printf("%i",n->i);
  while (n->next) {
    n = n->next;
    printf(" >> %i",n->i);
  }
}


struct node * insert_front(struct node *n, int data) {
  struct node *new = (struct node *)malloc(sizeof(struct node));
  new->i = data;
  new->next = n;
  return new;
}



struct node * free_list(struct node *n) {
  
  struct node *toReturn = n;
  struct node *hold;
  while (n->next) {
    hold = n->next;
    free(n);
    n = hold;
  }
  free(n);
  return toReturn;
  
}




int main() {
  struct node *list;
  list = (struct node *)malloc(sizeof(struct node));
  list->i = 34;
  list->next = 0;

  printf("List with one element: \n");
  print_list(list);
  printf("\n");

  int i = 32;

  for (i; i <= 62; i += 3) {
    list = insert_front(list,i);
    printf("List: \n");
    print_list(list);
    printf("\n");
  }

  list = free_list(list);
  printf("Cleared:\nList:\n");
  print_list(list);
  printf("\n");

  return 0;
}


