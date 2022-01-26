#ifndef DATA_STRUCTURE_H
# define DATA_STRUCTURE_H
# include <stdio.h>
# include <stdlib.h>
# include "arraylist.h"
# include "linkedlist.h"
# include "doublylist.h"

typedef struct node1 {
	int data;
	struct node* next;
} simpleNode;

typedef struct node2 {
	int data;
	struct node* prev;
	struct node* next;
} doubleNode;

#endif
