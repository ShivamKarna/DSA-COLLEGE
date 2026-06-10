/**
 * To Compile : 
 * gcc SinglyList.c helper.c -o sll
 * ./sll
 * */

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
void insert_at_beginning(SinglyList* list,int val)
{
    SinglyNode* new_node = create_singly_node(val);
    if(!new_node) return;
    if(!list->first){
        list->first = list->last = new_node;
    }else{
        new_node->next = list->first;
        list->first = new_node;
    }
};
void insert_at_end(SinglyList* list,int val)
{
    SinglyNode* new_node = create_singly_node(val);
    if(!new_node) return ;
    if(!list->first){
        list->first = list->last = new_node;
    }else{
        list->last->next = new_node;
        list->last = new_node;
    }
}
void insert_at_specific(SinglyList* list,int pos,int element){
    if(pos <= 1){
        insert_at_beginning(list,element);
        return;
    }
    SinglyNode* temp = list->first;

    for(int i= 1; i < pos - 1 && temp->next !=NULL ; i++){
        temp = temp->next;
    }
    // reached end
    if(temp->next == NULL){
        insert_at_end(list,element);
    }
    // somewhere in between
    SinglyNode* new_node = create_singly_node(element);
    if(!new_node) return ;

    new_node->next = temp->next;
    temp->next = new_node;

    printf(
        "%d INSERTED INTO LIST.\n",temp->data
    );
}

/**
 * DELETION FUNCTIONS:
 * delete_from_beginning
 * delete_from_end
 * delete_from_specific
 */
void delete_from_beginning(SinglyList* list){
    SinglyNode* temp = list->first;
    // list is empty
    if(list->first == NULL){
        fprintf(stderr, "List is Empty");
    }
    // only one node
    else if(list->first->next == NULL){
        // Node* temp = list->first;
        // list->first = list->last;
        // free(temp);
        free_singly_list(list);
    }
    // mutiple nodes
    else{
        SinglyNode* temp = list->first;
        list->first = list->first->next;
        printf("%d REMOVED FROM LIST\n",temp->data);
        free(temp);
    }
}
void delete_from_end(SinglyList* list){
    // list is empty
    if(list->first == NULL){
        fprintf(stderr, "List is Empty");
    }
    // only one node
    else if(list->first->next == NULL){
        // Node* temp = list->first;
        // list->first = list->last;
        // free(temp);
        free_singly_list(list);
    }
    else{
        SinglyNode* temp = list->first;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        SinglyNode* node_to_delete = temp->next;
        temp->next = NULL;
        list->last = temp;
        printf("%d DELETED FROM LIST.\n",node_to_delete->data);
        free(node_to_delete);
    }
}
void delete_from_specific(SinglyList* list,int pos){
    if(pos <= 1){
        delete_from_beginning(list);
        return;
    }

    SinglyNode* temp = list->first;
    for(int i = 1 ; i < pos -1  && temp->next != NULL ; i++){
        temp = temp->next;
    }
    // reached end
    if(temp->next == NULL){
        delete_from_end(list);
    }
    // somwehere in between
    SinglyNode* next_node = temp->next;

    temp->next = next_node->next;
    next_node->next = NULL;


    printf("%d REMOVED FROM LIST.\n",next_node->data);
    free(next_node);

}

// SEARCHING Function
bool search_element_in_singly(SinglyList* list,int target){
    bool found = false;
    if(list->first == NULL){
        fprintf(stderr,"Search Unsuccessfull, Empty List ! .\n");
    }
    else{
        SinglyNode* temp = list->first;
        while(temp != NULL){
            if(temp->data == target){
                printf("Element Found !, i.e. %d is in List \n",temp->data);
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
    SinglyList list;
    init_singly_list(&list);

    insert_at_beginning(&list,200);
    insert_at_beginning(&list,100);

    insert_at_end(&list,300);

    insert_at_specific(&list,2,1234);

    search_element_in_singly(&list,1234);
    // delete_from_beginning(&list);
    // delete_from_end(&list);
    // delete_from_specific(&list,2);


    print_singly_list(&list);
    free_singly_list(&list);
    return 0;
}



