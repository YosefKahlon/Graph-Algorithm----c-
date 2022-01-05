//
// Created by 97252 on 12/30/2021.
//

#ifndef TEST_GRAPH_H
#define TEST_GRAPH_H
#ifndef GRAPH_
#define GRAPH_



typedef struct GRAPH_NODE_ *pnode;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
<<<<<<< Updated upstream
    int weight;
    int color;
=======
>>>>>>> Stashed changes
    struct GRAPH_NODE_ *next;
} node, *pnode;

void insert_node_cmd(node **head, int id);

void build_graph_cmd(pnode *head, int size);

void removeInEdge(node *head, int id);

void removeOutEdge(node *dest);

node *getNode(node *head, int id);

void delete_node_cmd(pnode *head, int id);

void printGraph_cmd(pnode head); //for self debug


void printGraph(pnode *head);
void deleteGraph_cmd(pnode *head);

void shortsPath_cmd(pnode head);

void TSP_cmd(pnode head );

void add_edge(node *src, pnode dest, int weight);

int shortedPath(node **head, int src, int dest, int len);
<<<<<<< Updated upstream
=======
void TSP(pnode *head, int list[] , int size,int len);






void printGraph_cmd(pnode head); //for self debug
void shortsPath_cmd(pnode head);
void TSP_cmd(pnode head );




>>>>>>> Stashed changes


void TSP(pnode *head, int list[] , int size,int len);




#endif


#endif //TEST_GRAPH_H
