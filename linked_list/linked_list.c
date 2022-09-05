#include <stdlib.h>
#include <stdio.h>
#include <linked_list.h>

typedef struct _snode {
    int val;
    struct _snode *next;

} SNode;

typedef struct _slinked_list {
    SNode *begin;
    int size;   // Size of linked list
} LinkedList;

SNode *SNode_create(int val){
    SNode *snode = (SNode*) calloc(1, sizeof(SNode));
    snode->val=val;
    snode->next = NULL;
    return snode;
}

LinkedList *LinkedList_create(){
    LinkedList *linked_list = (LinkedList*)calloc(1, sizeof(LinkedList));
    linked_list->begin = NULL;
    return linked_list;
}

void addFirst(LinkedList *L, int val){
    SNode *p =  SNode_create(val);
    p->next = L->begin;
    L->begin = p;
    L->size++;
}

void addLast(LinkedList *L, int val){
    SNode *p = SNode_create(val);
    if(L->begin == NULL){
        L->begin = p;
    }else{
        //While aux !end, aux++
        SNode *aux = L->begin;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = p;
    }
    L->size++;
}

void print(LinkedList *L){
    SNode *p = L->begin;
    printf("Linked list: ");

    while(p != NULL){
        printf("%d -> ", p->val);
        p = p->next;
    }
    printf("NULL\n");
    
}
