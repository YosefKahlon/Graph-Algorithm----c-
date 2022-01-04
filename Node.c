//
// Created by 97252 on 1/2/2022.
//


#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "string.h"
#include "limits.h"



node *getNode(node *head, int id) {

    for (node *curr = head; curr != NULL; curr = curr->next) {

        if (curr->node_num == id) {

            return curr;
        }
    }
    return NULL;

}


void insert_node_cmd(node **head, int id) {

    //If already exists
    node *new_node = getNode(*head, id);
    if (new_node == NULL) { // create new node
        // malloc check
        new_node = (node *) malloc(sizeof(node));
        if (new_node == NULL) {
            exit(1); //The system dose not provide memory
        }

        new_node->next = NULL;
        new_node->node_num = id;
        new_node->edges = NULL;


        //find a spot for the new node
        node *curr = *head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new_node;

    } else { // node is exists so need to remove all the out edge
        //printf("node has been in the graph \n");
        removeOutEdge(new_node);
    }

}


void delete_node_cmd(node **head, int id) {
    removeInEdge(*head, id);
    pnode src = getNode(*head, id);
    removeOutEdge(src);

//    for (pnode curr = *head; curr->next != NULL; curr = curr->next) {
//        if (curr->next->node_num == id) {
//            pnode removeNode = curr->next;
//            curr->next = curr->next->next;
//            free(removeNode);
//        }
//    }
    pnode temp = *head;
    pnode prev=*head ;


    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->node_num == id) {
        *head = temp->next; // Changed head

        // (*headE) = ((temp)->edge);ZZ
        // deleteEdges(headE);

        free(temp); // free old head
        return;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->node_num!= id) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL)
        return;

    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp); // Free memory

}