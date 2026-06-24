#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

// Singly List Functions
void print_singly_list(const SinglyList* list) {
    SinglyNode* temp = list->first;
    printf("Singly List Is : ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void free_singly_list(SinglyList* list) {
    SinglyNode* current = list->first;
    while (current != NULL) {
        SinglyNode* nextNode = current->next;
        free(current);
        current = nextNode;
    }
    list->first = list->last = NULL;
    printf("Entire SinglyList safely freed from memory.\n");
}
void init_singly_list(SinglyList* list){
    list->first = list->last = NULL;
}
SinglyNode* create_singly_node(int val){
    SinglyNode* new_node = (SinglyNode*)malloc(sizeof(SinglyNode));
    if(new_node == NULL){
        fprintf(stderr,"Failed to allocate Memory !.\n");
    }
    new_node->data = val;
    new_node->next = NULL;
    return new_node;
}

// Doubly List Functions
void print_doubly_list(const DoublyList* list){
    DoublyNode* temp = list->first;
    printf("Doubly List is : ");
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp= temp->next;
    }
    printf("NULL\n");
}
void free_doubly_list(DoublyList* list){
    DoublyNode* current = list->first;
    while(current != NULL){
        DoublyNode* nextNode = current->next;
        free(current);
        current = nextNode;
    }
    list->first = list->last = NULL;
    printf("Entire DoublyList safely freed from memory.\n");
}
void init_doubly_list(DoublyList* list){
    list->first = list->last = NULL;
}
DoublyNode* create_doubly_node(int val){
    DoublyNode* new_node = (DoublyNode*)malloc(sizeof(DoublyNode));
    if(new_node == NULL){
        fprintf(stderr,"Failed to allocate Memory !.\n");
    }
    new_node->data = val;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}
