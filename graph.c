#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "string.h"
#include "limits.h"



void deleteGraph_cmd(pnode *head) {
    pnode curr = *head;
    if (curr == NULL) {
        return;
    }

    while (curr != NULL) {
        while (curr->edges != NULL) {
            removeOutEdge(curr);
        }
        pnode temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(curr);

}

void build_graph_cmd(pnode *head, int size) {

    int nodeSize = size;
    if (nodeSize < 0) {
        perror("Invalid number\n");
    }

    pnode *curr = head;

    for (int i = 0; i < size; i++) {
        pnode newNode = (pnode) malloc(sizeof(node));
        if (newNode == NULL) {
            printf("the system not provide memory\n");
            exit(1); //the system not provide memory
        }
        newNode->node_num = i;
        newNode->next = NULL;
        newNode->edges = NULL;

        *curr = newNode;
        curr = &(*newNode).next;


    }


}

void printGraph(pnode *head) {

    printf("id --- edge \n");
    printf("----|------\n");
    for (pnode curr = *head; curr != NULL; curr = curr->next) {
        printf("%d --> ", curr->node_num);
        pedge currE = curr->edges;
        while (currE != NULL) {
            printf(" (%d -> %d| %d ) --> ", curr->node_num, currE->endpoint->node_num, currE->weight);
            currE = currE->next;
        }
        printf(" (NULL)");
        printf("\n");
    }
    printf("----|------\n");
}


//int main() {
//
//
//    node *head = NULL;
//
//
//    int i = 0;
//    int j = 0;
//    char graphc[100] = "A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 n 3 T 3 2 1 3 B 5 0 4 2 1 B 2 1 3 5 1 T 3 2 1 3 D 2 T 2 3 0";
//    char graph[100] = "";
//    while (graphc[i] != '\0') {
//        if (graphc[i] != 32) {
//            graph[j] = graphc[i];
//            i++;
//            j++;
//        } else {
//            i++;
//        }
//    }
//
//
//    i = 0;
//    while (graph[i] != '\0') {
//
//        if (graph[i] == 'A') {
//            deleteGraph_cmd(&head);
//            i++;
//            int size = (int) (graph[i] - '0');
//
//            build_graph_cmd(&head, size); // build the node
//            i++;
//            while (graph[i] == 'n') {
//                i++;
//                pnode src = getNode(head, (int) (graph[i] - '0'));
//                i++;
//                while (graph[i] != 'n') {
//                    if (!(graph[i] >= 'A' && graph[i] <= 'Z') && !(graph[i] >= 'a' && graph[i] <= 'z')) {
//                        pnode dest = getNode(head, (int) (graph[i] - '0'));
//                        i++;
//                        int weight = (int) (graph[i] - '0');
//                        i++;
//                        add_edge(src, dest, weight);
//                    } else {
//                        break;
//                    }
//                }
//            }
//
//
//        }
//        if (graph[i] == 'B') {
//            i++;
//            pnode src;
//            int id = (int) graph[i] - '0';
//            insert_node_cmd(&head, id);
//            src = getNode(head, id);
//            i++;
//
//            while (!(graph[i] >= 'A' && graph[i] <= 'Z') && !(graph[i] >= 'a' && graph[i] <= 'z') &&
//                   graph[i] != '\0') {
//
//                pnode dest = getNode(head, (int) (graph[i] - '0'));
//                i++;
//                int weight = (int) (graph[i] - '0');
//                i++;
//                add_edge(src, dest, weight);
//            }
//
//        }
//        printGraph(&head);
//
//        if (graph[i] == 'D') {
//            i++;
//            int id = (int) graph[i] - '0';
//            delete_node_cmd(&head, id);
//            i++;
//        }
//
//
//        if (graph[i] == 'S') {
//            i++;
//            pnode src = getNode(head, graph[i] - '0');
//            i++;
//            pnode dest = getNode(head, graph[i] - '0');
//
//            int max = 0;
//            for (pnode curr = head; curr != NULL; curr = curr->next) {
//
//                if (curr->node_num > max) {
//                    max = curr->node_num;
//                }
//
//
//            }
//            int len = max + 1;
//
//            int ans = shortedPath(&head, src->node_num, dest->node_num, len);
//
//            printf("dijkstra ans %d\n", ans);
//            i++;
//        }
//
//        if (graph[i] == 'T') {
//            i++;
//            int size = graph[i] - '0';
//            i++;
//            int list[size];
//            for (int k = 0; k < size; k++) {
//                pnode curr = getNode(head, graph[i] - '0');
//                list[k] = curr->node_num;
//                i++;
//            }
//
//
//
//            TSP(&head, list , size, 5);
//            i++;
//        }
//
//
//
//
//
//    }
//
//
//    return 0;
//}







