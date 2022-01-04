#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "graph.h"

int main() {


    node *head = NULL;




    char ch = '0';
    int numOfNode;
    int destNode;
    int weight;
    int srcNode;
    int size;
    int max_node = 0;


    while (scanf("%c", &ch) != 0 &&ch != EOF) {


        if ( ch == 'A') {

            deleteGraph_cmd(&head);

            scanf("%d", &numOfNode);

            build_graph_cmd(&head, numOfNode); // build the node
            scanf("%c", &ch);


            while (scanf("%c", &ch) != 0 && ch == 'n') {


                scanf("%d", &srcNode);
                pnode src = getNode(head, srcNode);


                while (scanf("%d", &destNode) != 0 && scanf("%d", &weight) != 0) {

                    pnode dest = getNode(head, destNode);


                    add_edge(src, dest, weight);

                }







            }
        }


        pnode src;
        if (ch == 'B') {
        

            scanf("%d", &srcNode);
           

            insert_node_cmd(&head, srcNode);
            src = getNode(head, srcNode);
            while (scanf("%d", &destNode) != 0 && scanf("%d", &weight) != 0) {

                pnode dest = getNode(head, destNode);


                add_edge(src, dest, weight);

            }


        }


        if (ch == 'D') {
         

            scanf("%d", &srcNode);
       
            delete_node_cmd(&head, srcNode);
     
        }

        if (ch == 'S') {
            scanf("%d", &srcNode);
            pnode src = getNode(head, srcNode);
            scanf("%d", &destNode);
            pnode dest = getNode(head, destNode);

            max_node = 0;
            for (pnode curr = head; curr != NULL; curr = curr->next) {

                if (curr->node_num > max_node) {
                    max_node = curr->node_num;
                }


            }
            int len = max_node + 1;

            int ans = shortedPath(&head, src->node_num, dest->node_num, len);

            printf("Dijsktra shortest path: %d ",ans);
            printf("\n");

        }

        if (ch == 'T') {
                for (pnode curr = head; curr != NULL; curr = curr->next) {

                    if (curr->node_num > max_node) {
                        max_node = curr->node_num;
                    }


                }
            scanf("%d", &size);
            int *num = (int *) malloc(sizeof(int) * size);
            if (num == NULL) {
                exit(1);
            }

            for (int j = 0; j < size; j++) {
                scanf("%d", &srcNode);
                num[j] = srcNode;
            }
            int len = max_node + 1;


            TSP(&head, num, size, len);
            free(num);
        }


    
    }
    // free the memory of the graph
    deleteGraph_cmd(&head);

    return 0;
}