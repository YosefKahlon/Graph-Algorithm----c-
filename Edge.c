//
// Created by 97252 on 1/2/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "string.h"
#include "limits.h"

void removeOutEdge(node *dest)
{

    //node out of edge
    if (dest->edges == NULL)
    {
        return;
    }

    edge *curr = dest->edges;
    while (curr != NULL)
    {
        edge *remove = curr;
        curr = curr->next;
        
        free(remove);
    }

    dest->edges = NULL;
<<<<<<< Updated upstream

=======
>>>>>>> Stashed changes
}

void removeInEdge(node *head, int id)
{
    if (head == NULL)
    {
        return;
    }
    pnode dest = getNode(head, id);

    for (pnode curr = head; curr != NULL; curr = curr->next)
    {

        pedge currEdge = curr->edges;
        pedge *pointerToCurrEdge = &curr->edges;
        while (currEdge != NULL)
        {
            if (currEdge->endpoint == dest)
            {
                *pointerToCurrEdge = currEdge->next;
                free(currEdge);
                currEdge = *pointerToCurrEdge;
<<<<<<< Updated upstream
            } else {
=======
            }
            else
            {
>>>>>>> Stashed changes
                pointerToCurrEdge = &currEdge->next;
                currEdge = currEdge->next;
            }
        }
<<<<<<< Updated upstream

=======
>>>>>>> Stashed changes
    }
}
//A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 n 3 T 3 2 1 3 B 5 0 4 2 1 B 2 1 3 5 1 T 3 2 1 3 D 2 T 2 3 0
void add_edge(node *src, pnode dest, int weight)
{

    edge* new_edge = (edge*)malloc(sizeof(edge));
    if (new_edge == NULL)
    {
        exit(1);
    }

    new_edge->endpoint =dest;
    new_edge->weight = weight;
    new_edge->next = NULL;

    // curr =NULL;
     
    if (src->edges == NULL)
    {   
      

        src->edges = new_edge;
        //return;
        
    }
    else
    {       
      pedge curr=src->edges;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = new_edge;
<<<<<<< Updated upstream
=======
        
       
>>>>>>> Stashed changes
    }


    
}
