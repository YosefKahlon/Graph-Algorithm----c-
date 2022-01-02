#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"
// typedef struct Node
// {
//     int id;
//     int data;
//     int prev;
//     struct Node *next;
//     struct edges *edge;
// } Node;
// typedef struct edges
// {

//     int dest;
//     int weight;
//     struct edges *next;
// } edges;

Node *newNode(int id, int data, Node *next)
{
    Node *p = (Node *)malloc(sizeof(Node));
    // struct edges *edgeh3 = NULL;
    // edgeh3 = (struct edges *)malloc(sizeof(struct edges));
    // struct edges **heade3 = NULL;
    // heade3 = (struct edges **)malloc(sizeof(struct edges));

    p->data = data;
    p->next = next;
    p->edge = NULL;
    p->id = id;
    return p;
}
void insertLast(int id, int data, struct Node **head)
{
    struct Node **p = head;
    while (*p)
        p = &((*p)->next);
    *p = newNode(id, data, NULL);
}

edges *newedge(int dest, int data, edges *next)
{
    edges *p = (edges *)malloc(sizeof(edges));

    p->dest = dest;
    p->weight = data;
    p->next = NULL;
    return p;
}

void insertEdge(int dest, int data, struct edges **edge)
{
    struct edges **p = edge;
    while (*p && (*p)->dest != -1)
    {
        p = &((*p)->next);
    };
    *p = newedge(dest, data, NULL);
}

Node **creatgrph(int numnode)
{

    struct Node **head = NULL;
    head = (struct Node **)malloc(sizeof(struct Node));
    int i = 0;
    if (numnode > 0)
    {

        while (i != numnode)
        {
            insertLast(i, 0, head);
            i = i + 1;
        }
    }

    return head;
}

void deleteEdges(struct edges **head_ref)
{
    // Store head edge
    struct edges *temp = *head_ref;

    // If head node itself holds the key to be deleted
    while (temp)
    {
        if (temp != NULL)
        {
            *head_ref = temp->next; // Changed head
            free(temp);             // free old head
        }
        temp = *head_ref;
    }
    free(temp); // Free memory
}
void deleteNode(struct Node** head_ref, int key)
{
    // Store head node
    struct Node *temp = *head_ref, *prev;
    struct edges **headE = NULL;
    headE = (struct edges **)malloc(sizeof(struct edges));
 
    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->id == key) {
        *head_ref = temp->next; // Changed head
        
       // (*headE) = ((temp)->edge);ZZ
       // deleteEdges(headE);
        
        free(temp); // free old head
        return;
    }
 
    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->id != key) {
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
void deleteEdgeDest(struct edges** head_ref, int key)
{
    // Store head node
    struct edges *temp = *head_ref, *prev;
 
    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->dest == key) {
        *head_ref = temp->next; // Changed head
        free(temp); // free old head
        return;
    }
 
    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->dest != key) {
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

