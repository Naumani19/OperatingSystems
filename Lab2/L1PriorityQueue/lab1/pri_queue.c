#include <stdlib.h>
#include <stdio.h>
#include "pri_queue.h"
/** @file pri_queue.c */
static Node_ptr_t head = NULL;
/**
 * Insert a Node into a priority queue.
 * @param priority
 * @param data
 * @author Sameer Naumani
 */

void PQ_insert(int priority, char * data) {
 //FIX THIS
    Node_ptr_t tmp;
    
    Node_ptr_t Node = malloc(sizeof(Node_t));
    Node->priority = priority;
    Node-> data = data;
    
    if(head == NULL || Node->priority > head->priority){
        Node->next =head;
        head = Node;
    }
    else{
        tmp = head;
        while(tmp->next != NULL && tmp->next->priority > Node->priority){
            tmp=tmp->next;
            printf("%d\n", tmp->priority);
        }
        
        Node->next = tmp-> next;
        tmp->next= Node;
            
        
    }
  
    
    
} 
/**
 * Delete and return the node with the highest priority.
 * @return The highest priority Node.
 */
Node_ptr_t PQ_delete() {
 //FIX THIS
 //Fix the links by detaching the link from the linked list but this still takes up space
 // Free the space 
    if (PQ_get_size() == 0) {
        return NULL;
    }
    else{
        head ++;
    }
    return head-> next;
   
    return NULL;
}

/**
 * Do NOT modify this function.
 * @return A pointer to the head of the list.  (NULL if list is empty.)
 */
Node_ptr_t PQ_get_head() {
    return head;
}

/**
 * Do NOT modify this function.
 * @return the number of items in the queue
 */
int PQ_get_size() {
    int size = 0;
    Node_ptr_t tmp;
    for(tmp = head; tmp != NULL; tmp = tmp->next, size++)
        ;
    return size;
}


