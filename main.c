#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"

void print(struct Node **head){
    struct Node **current2 = head;

            while (*current2)
            {
                printf("  %d--> \n", (*current2)->id);
                struct edges **edgeh12 = NULL;
                edgeh12 = (struct edges **)malloc(sizeof(struct edges));
                (*edgeh12) = ((*current2)->edge);

                while ((*edgeh12))
                {
                    printf("\n%d-->%d W:%d\n", (*current2)->id, (*edgeh12)->dest, (*edgeh12)->weight);
                    edgeh12 = &((*edgeh12)->next);
                };
                current2 = &((*current2)->next);
            };
        
}
int main ()
{
    
    struct Node **head = NULL;
    head = (struct Node **)malloc(sizeof(struct Node));
    struct edges **headE = NULL;
    headE = (struct edges **)malloc(sizeof(struct edges));
    char ch = '0';
    int src;
    int numOfNodes;
    

    while (ch != EOF)
    {

        if (scanf("%c", &ch) != 0 && ch == 'A')
        {

            scanf("%d", &numOfNodes);
            head = creatgrph(numOfNodes);
            struct Node **current = head;
            while (*current)
            {
                printf("  %d--> \n", (*current)->id);

                current = &((*current)->next);
            };
        };

        scanf("%c", &ch);

        while (scanf("%c", &ch) != 0 && ch == 'n')
        {
            scanf("%d", &src);
            int dest;
            int weight;
            while (scanf("%d", &dest) != 0 && scanf("%d", &weight) != 0)
            {
                struct Node **current2 = head;
                while (*current2)
                {
                    if ((*current2)->id == src)
                    {
                        if ((*current2)->edge == NULL)
                        {
                            struct edges *edgeh12 = NULL;
                            edgeh12 = (struct edges *)malloc(sizeof(struct edges));
                            (*current2)->edge = edgeh12;
                            (*current2)->edge->dest = dest;
                            (*current2)->edge->weight = weight;
                        }
                        else
                        {
                            (*headE) = (*current2)->edge;
                            insertEdge(dest, weight, headE);
                        }
                        
                    };
                    current2 = &((*current2)->next);
                };
            };
        };
        if (ch == 'B')
        {
            printf("CH= %C\n", ch);
            
            while (scanf("%d", &src) != 0)
            { 
                int dest;
                int weight;
                int flag = 0;
                
                struct Node **current2 = head;
                while (*current2)
                {

                    if ((*current2)->id == src)
                    {
                        flag = 1;

                        printf("src= %d dest= %d W:%d", (*current2)->id, dest, weight);
                        (*headE) = (*current2)->edge;
                        deleteEdges(headE);
                        (*current2)->edge = NULL;
                      

                        while (scanf("%d", &dest) != 0 && scanf("%d", &weight) != 0)
                        {
                            if ((*current2)->edge == NULL)
                            {
                                struct edges *edgeh12 = NULL;
                                edgeh12 = (struct edges *)malloc(sizeof(struct edges));
                                (*current2)->edge = edgeh12;
                                (*current2)->edge->dest = dest;
                                (*current2)->edge->weight = weight;
                            }
                            else
                            {
                                (*headE) = (*current2)->edge;
                                insertEdge(dest, weight, headE);
                            };
                        };
                    };
                    current2 = &((*current2)->next);

                };
                if (flag == 0)
                {
                    current2 = head;
                    insertLast(src, 0, head);
                    numOfNodes++;
                    while (*current2)
                    {
                        if ((*current2)->id == src)
                        {
                            while (scanf("%d", &dest) != 0 && scanf("%d", &weight) != 0)
                            {
                                printf("src= %d dest= %d W:%d", (*current2)->id, dest, weight);
                                if ((*current2)->edge == NULL)
                                {
                                    struct edges *edgeh12 = NULL;
                                    edgeh12 = (struct edges *)malloc(sizeof(struct edges));
                                    (*current2)->edge = edgeh12;
                                    (*current2)->edge->dest = dest;
                                    (*current2)->edge->weight = weight;
                                }
                                else
                                {
                                    (*headE) = (*current2)->edge;
                                    insertEdge(dest, weight, headE);
                                };
                                
                            };
                        };
                        current2 = &((*current2)->next);
                    };
                };
            };
      
        
        };
        if (ch == 'D')
        {
            int Node;
            scanf("%d",&Node);
            
            numOfNodes=numOfNodes-1;
            struct Node **current = head;
            // while (*current)
            // {
                
            //     (*headE)=(*current)->edge;
            //     deleteEdgeDest(headE,Node);
            //     print(head);

            //     current = &((*current)->next);
            // };

            deleteNode(head,Node);
            // print(head);
            // break;

        }
        
        
        
        
        
        
        
        return 0;
    }
}
