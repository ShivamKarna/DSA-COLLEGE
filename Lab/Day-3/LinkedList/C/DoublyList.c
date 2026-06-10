/**
 * To Compile : 
 * gcc DoublyList.c helper.c -o dll
 * ./dll
 * */

// Doubly Linked List
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include "helper.h"

/**
 * INSERTION FUNCTIONS:
 * insert_at_beginning 
 * insert_at_end
 * insert_at_specific
*/ 
void insert_at_beginning(DoublyList* list,int val){
    DoublyNode* new_node = create_doubly_node(val);
    if(!new_node) return;
    if(!list->first){
        list->first = list->last = new_node;
    }else{
        new_node->next = list->first;
        list->first->prev = new_node;
        list->first = new_node;
    }
    printf("%d INSERTED INTO BEGINNING.\n\n",new_node->data);
}
void insert_at_end(DoublyList* list,int val){
    DoublyNode* new_node = create_doubly_node(val);
    if(!new_node) ;
    if(!list->first){
        list->first = list->last = new_node;
    }
    else{
        list->last->next = new_node;
        new_node->prev = list->last;
        list->last = new_node;
    }
    printf("%d INSERTED INTO END.\n\n",new_node->data);

}
void insert_at_specific(DoublyList* list,int pos,int element){
    if(pos <= 1){
        insert_at_beginning(list,element);
        return;
    }
    DoublyNode* temp = list->first;

    for(int i= 1; i < pos - 1 && temp->next !=NULL ; i++){
        temp = temp->next;
    }
    // reached end
    if(temp->next == NULL){
        insert_at_end(list,element);
    }
    // somwehere in between
    DoublyNode* new_node = create_doubly_node(element);
    if(!new_node) return;

    DoublyNode* node_after_temp = temp->next;

    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = node_after_temp;
    node_after_temp->prev = new_node;

    printf("%d INSERTED to List at Position : %d\n\n",new_node->data,pos);
}
/**
 * DELETION FUNCTIONS:
 * delete_from_beginning
 * delete_from_end
 * delete_from_specific
 */
void delete_from_beginning(DoublyList* list){
    DoublyNode* temp = list->first;
    // list is empty
    if(list->first == NULL){
        fprintf(stderr,"List is Empty !");
    }
    // only one node
    else if(list->first->next == NULL){
        free_doubly_list(list);
    }
    // multiple nodes
    else{
        DoublyNode* temp = list->first;
        list->first = list->first->next;
        temp->next = NULL;
        list->first->prev= NULL;
        printf("%d REMOVED FROM LIST.\n\n",temp->data);
        free(temp);
    }

}
void delete_from_end(DoublyList* list){
    // list is empty
    if(list->first == NULL){
        fprintf(stderr, "List is Empty");
    }
    // only one node
    else if(list->first->next == NULL){
        free_doubly_list(list);
    }
    else{
        DoublyNode* temp = list->first;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        list->last = temp->prev;
        list->last->next = NULL;
        temp->prev = NULL;
        printf("%d DELETED FROM LIST.\n\n",temp->data);
        free(temp);
    }
}
void delete_from_specific(DoublyList* list,int pos){
    if(pos <= 1){
        delete_from_beginning(list);
        return;
    }
    DoublyNode* temp = list->first;
    for(int i = 1 ; i < pos -1  && temp->next != NULL ; i++){
        temp = temp->next;
    }
    // Optional to show
    if(temp->next == NULL){
        printf("Position %d out of bounds.\n\n", pos);
        return; 
    }

    // reached end
    if(temp->next == NULL){
        delete_from_end(list);
        return;
    }
    DoublyNode* node_to_delete = temp->next;
    DoublyNode* node_after = temp->next->next;

    if(node_after == NULL){
        delete_from_end(list);
        return;
    }

    temp->next = node_after;
    node_after->prev = temp; 

    node_to_delete->prev = node_to_delete->next = NULL;

    printf("%d DELETED from List\n\n",node_to_delete->data);
    free(node_to_delete);
}
// SEARCHING FUNCTION
bool search_element_in_doubly(DoublyList* list,int target){
    bool found = false;
    if(list->first == NULL){
        fprintf(stderr,"Search Unsuccessfull, Empty List ! .\n");
    }
    else{
        DoublyNode* temp = list->first;
        while(temp != NULL){
            if(temp->data == target){
                printf("\nElement Found !, i.e. %d is in List \n\n",temp->data);
                found = true;
            }
            temp = temp->next;
        }
    }
    if(found == false){
        printf("Element not found ! \n");
    }
}
int main(){

    DoublyList list;
    init_doubly_list(&list);

    insert_at_beginning(&list,100);
    insert_at_end(&list,200);
    insert_at_specific(&list,2,300);

    // delete_from_beginning(&list);
    // delete_from_end(&list);
    // delete_from_specific(&list,3);

    // search_element_in_doubly(&list,200);



    print_doubly_list(&list);
    free_doubly_list(&list);
    return 0;
}