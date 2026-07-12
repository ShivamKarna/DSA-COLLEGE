#pragma once

typedef struct SinglyNode{
    int data;
    struct SinglyNode* next;
} SinglyNode; 

typedef struct{
    SinglyNode* first;
    SinglyNode* last;
} SinglyList;

typedef struct DoublyNode{
    int data;
    struct DoublyNode* next;
    struct DoublyNode* prev;
} DoublyNode;

typedef struct{
    DoublyNode* first;
    DoublyNode* last;
} DoublyList;

// Singly List Functions
void print_singly_list(const SinglyList* list);
void free_singly_list(SinglyList* list);
void init_singly_list(SinglyList* list);
SinglyNode* create_singly_node(int val);

// Doubly List Functions
void print_doubly_list(const DoublyList* list);
void free_doubly_list(DoublyList* list);
void init_doubly_list(DoublyList* list);
DoublyNode* create_doubly_node(int val);
