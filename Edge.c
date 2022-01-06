//
// Created by 97252 on 1/2/2022.
//


#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "string.h"
#include "limits.h"



void removeOutEdge(node *dest) {

    //node out of edge
    if (dest->edges == NULL) {
        exit(1);
    }

    edge *curr = dest->edges;
    while (curr != NULL) {
        edge *remove = curr;
        curr = curr->next;

        free(remove);

    }
    

    dest->edges = NULL;

}

void removeInEdge(node *head, int id) {
    if (head == NULL) {
        return;
    }
    pnode dest = getNode(head, id);



    for (pnode curr = head; curr != NULL; curr = curr->next) {

        pedge currEdge = curr->edges;
        pedge *pointerToCurrEdge = &curr->edges;
        while (currEdge != NULL) {
            if (currEdge->endpoint == dest) {
                *pointerToCurrEdge = currEdge->next;
                free(currEdge);
                currEdge = *pointerToCurrEdge;
            } else {
                pointerToCurrEdge = &currEdge->next;
                currEdge = currEdge->next;

            }


        }

    }


}

void add_edge(node *src, pnode dest, int weight) {
    if(src!=NULL&&dest!=NULL){
    pedge new_edge = (pedge) malloc(sizeof(edge));
    if (new_edge == NULL) {
        free(new_edge);
        exit(1);
    }


    new_edge->endpoint = dest;
    new_edge->weight = weight;
    new_edge->next = NULL;


    
    if (src->edges == NULL) {
        
        src->edges = new_edge;
        
    } else {
        pedge curr = src->edges;
        while (curr->next != NULL) {
           
            curr = &(*curr->next);
        }
        curr->next = new_edge;
    }


    }
}


