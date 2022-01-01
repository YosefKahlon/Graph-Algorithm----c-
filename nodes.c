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
    struct edges **heade3 = NULL;
    heade3 = (struct edges **)malloc(sizeof(struct edges));

    p->data = data;
    p->next = next;
    (*heade3) = p->edge;
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
int main()
{
    struct Node **head = NULL;
    head = (struct Node **)malloc(sizeof(struct Node));
    char ch;
    int node;
    int numOfNodes;
    scanf("%c", &ch);
    while (ch != 'z')
    {
        if (ch == 'A')
        {
            scanf("%d", &node);
            numOfNodes = node;
            if (node > 0)
            {
                head = creatgrph(numOfNodes);
            }

            struct Node **current = head;
            while (*current)
            {
                printf("  %d--> \n", (*current)->id);

                current = &((*current)->next);
            }
        }
        int nodeEdge;
        scanf("%c", &ch);
        scanf("%d", &nodeEdge);
        while (ch == 'n')
        {

            

            struct Node **current2 = head;
            while (*current2)
            {
                char weightu;
                char destu;
                int weightu2;
                int destu2;

                if ((*current2)->id == (nodeEdge))

                {

                    scanf("%c", &destu);
                    printf("befor while: %d\n", destu);
                    scanf("%c", &weightu);

                    destu2 = (int)destu;

                    while (destu != 'n')
                    {

                        destu2 = destu - '0';
                        printf("destu2= %d\n", destu2);

                        weightu2 = weightu - '0';
                        printf("weightu2= %d\n", weightu2);
                        printf("destu2= %d\n", destu2);
                        struct edges *edgeh12 = NULL;
                        edgeh12 = (struct edges *)malloc(sizeof(struct edges));
                        (*current2)->edge = edgeh12;
                        (*current2)->edge->dest = destu2;
                        (*current2)->edge->weight = weightu2;
                        printf("\n%d-->%d W:%d\n", (*current2)->id, (*current2)->edge->dest, (*current2)->edge->weight);
                        scanf("%c", &destu);
                        destu2 = destu;
                        printf("destu2= %d\n", destu2);

                        scanf("%c", &weightu);
                    };
                    printf("------------------------------------------");
                };
                current2 = &((*current2)->next);
            };

            scanf("%d", &nodeEdge);
        };
    }
    return 0;
}
