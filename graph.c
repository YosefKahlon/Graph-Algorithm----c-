#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "string.h"
#include "limits.h"

void deleteGraph_cmd(pnode *head)
{
    pnode curr = *head;
    if (curr == NULL)
    {
        return;
    }

    while (curr != NULL)
    {
        while (curr->edges != NULL)
        {
            removeOutEdge(curr);
        }
        pnode temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(curr);

    
    
}

void build_graph_cmd(pnode *head, int size)
{

    int nodeSize = size;
    if (nodeSize < 0)
    {
        perror("Invalid number\n");
    }

    pnode *curr = head;

    for (int i = 0; i < size; i++)
    {
        pnode newNode = (pnode)malloc(sizeof(node));
        if (newNode == NULL)
        {
            //  printf("the system dose not provide memory\n");
            exit(1);
        }

        newNode->node_num = i;
        newNode->next = NULL;
        newNode->edges = NULL;

        *curr = newNode;
        curr = &(*newNode).next;
    }
    
}

void printGraph(pnode *head)
{

    printf("id --- edge \n");
    printf("----|------\n");
    for (pnode curr = *head; curr != NULL; curr = curr->next)
    {
        printf("%d --> ", curr->node_num);
        pedge currE = curr->edges;
        while (currE != NULL)
        {
            printf(" (%d -> %d| %d ) --> ", curr->node_num, currE->endpoint->node_num, currE->weight);
            currE = currE->next;
        }
        printf(" (NULL)");
        printf("\n");
    }
    printf("----|------\n");
}
