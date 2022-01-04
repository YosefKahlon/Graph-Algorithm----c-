//
// Created by 97252 on 12/30/2021.
//

#ifndef TEST_GRAPH_H
#define TEST_GRAPH_H
#ifndef GRAPH_
#define GRAPH_



typedef struct GRAPH_NODE_ *pnode;;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
   /// int weight;
    //int color;
    struct GRAPH_NODE_ *next;
} node, *pnode;



//-------node------------------
void insert_node_cmd(node **head, int id);
void delete_node_cmd(pnode *head, int id);
node *getNode(node *head, int id);



//-------edge----------------
void removeInEdge(node *head, int id);
void removeOutEdge(node *dest);
void add_edge(node *src, pnode dest, int weight);




//-----graph----------------
void build_graph_cmd(pnode *head, int size);
void printGraph(pnode *head);
void deleteGraph_cmd(pnode *head);




//-----algo----------------
int shortedPath(node **head, int src, int dest, int len);
void TSP(pnode *head, int list[] , int size,int len);






// void printGraph_cmd(pnode head); //for self debug
// void shortsPath_cmd(pnode head);
// void TSP_cmd(pnode head );










#endif


#endif //TEST_GRAPH_H
