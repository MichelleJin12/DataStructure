#ifndef DATA_STRUCTURE_H
# define DATA_STRUCTURE_H
# include <stdio.h>
# include <stdlib.h>
# include "arraylist.h"
# include "linkedlist.h"
# include "doublylist.h"
# include "polylist.h"
# include "arraystack.h"

/*
circular linked list
*/
LinkedList* createCircularLinkedList();
int addCLLElement(LinkedList* pList, int position, ListNode element);
int removeCLLElement(LinkedList* pList, int position);
ListNode* getCLLElement(LinkedList* pList, int position);
void clearCircularLinkedList(LinkedList* pList);
int getCircularLinkedListLength(LinkedList* pList);
void deleteCircularLinkedList(LinkedList* pList);
void displayCircularLinkedList(LinkedList* pList);




#endif
