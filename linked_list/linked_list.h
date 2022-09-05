#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct _snode SNode;
typedef struct _slinked_list LinkedList;

SNode *SNode_create(int val);
LinkedList *LinkedList_create();

void addFirst(LinkedList *L, int val);

void addLast(LinkedList *L, int val);

void print(LinkedList *L);

#endif