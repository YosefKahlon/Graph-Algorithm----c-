#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int id;
    int data;
    struct Node *next;
    struct edges *edge;
} Node;
typedef struct edges
{

    int dest;
    int weight;
    struct edges *next;
} edges;

Node *newNode(int id, int data, Node *next)
{
    Node *p = (Node *)malloc(sizeof(Node));
    struct edges *edgeh3 = NULL;
    edgeh3 = (struct edges *)malloc(sizeof(struct edges));
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
    struct edges *temp = *head_ref, *prev;

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

int main()
{
    struct Node **head = NULL;
    head = (struct Node **)malloc(sizeof(struct Node));
    struct edges **headE = NULL;
    headE = (struct edges **)malloc(sizeof(struct edges));
    char ch = '0';
    int src;
    int numOfNodes;
    // scanf("%c", &ch);

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
                        // struct edges *edgeh12 = NULL;
                        // edgeh12 = (struct edges *)malloc(sizeof(struct edges));
                        // (*current2)->edge = edgeh12;
                        // (*current2)->edge->dest = dest;
                        // (*current2)->edge->weight = weight;
                        // printf("TAKALAAA");
                        // printf("\n%d-->%d W:%d\n", (*current2)->id, (*current2)->edge->dest, (*current2)->edge->weight);
                    };
                    current2 = &((*current2)->next);
                };
            };
        };
        if (ch == 'B')
        {
            printf("CH= %C\n", ch);
            //insertLast(numOfNodes,0,head);
            // numOfNodes++;
            while (scanf("%d", &src) != 0)
            { //printf("src=%d",src);
                int dest;
                int weight;
                int flag = 0;
                //printf("dest=%d  weight=%d",dest,weight);
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
                        // struct edges *edgeh12 = NULL;
                        // edgeh12 = (struct edges *)malloc(sizeof(struct edges));
                        // (*current2)->edge = edgeh12;
                        // (*current2)->edge->dest = dest;
                        // (*current2)->edge->weight = weight;
                        // printf("\n%d-->%d W:%d\n", (*current2)->id, (*current2)->edge->dest, (*current2)->edge->weight);
                        // ----------------------------------

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
            printf("------------------");
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
        };

        printf("----------");
        //to do insert edge!!
    };
    return 0;
}
