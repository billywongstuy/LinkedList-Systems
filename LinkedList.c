#include <stdio.h>
#include <stdlib.h>

struct node {int i; struct node *next; };

void print_list(struct node *n) {
  struct node * temp = n;
  while (temp->next) {
    printf("%d > ",n->i);
    printf("\n\n %lu \n",temp);
    temp = temp->next;
  }
  printf("%d\n",temp->i);
}


struct node * insert_front(struct node *n, int data) {
  struct node * temp = (struct node *)malloc(sizeof(struct node));
  temp->i = data;
  temp->next = n;
  return temp;
}


struct node * free_list(struct node *n) {
  while (n->next) {
    free(n);
    n = n->next;
  }
  return n;
}


int main() {
  struct node *som = (struct node *)malloc(sizeof(struct node));
  som->i = 4;
  insert_front(som,9);
  insert_front(som,45);
  //print_list(som);
  printf("1:%d,",som->i);
  printf("2:%d,",som->next->i);
  printf("3:%d,",som->next->next->i);
  return 0;
}


