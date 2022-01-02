#ifndef _node_h
#define _node_h
typedef struct Node
{
    int id;
    int data;
    int prev;
    struct Node *next;
    struct edges *edge;
} Node;
typedef struct edges
{

    int dest;
    int weight;
    struct edges *next;
} edges;
Node *newNode(int id, int data, Node *next);
void insertLast(int id, int data, struct Node **head);
edges *newedge(int dest, int data, edges *next);
void insertEdge(int dest, int data, struct edges **edge);
Node **creatgrph(int numnode);
void deleteEdges(struct edges **head_ref);
void deleteNode(struct Node** head_ref, int key);
void deleteEdgeDest(struct edges** head_ref, int key);



#endif