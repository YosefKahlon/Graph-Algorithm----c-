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
<<<<<<< Updated upstream
=======
                    
>>>>>>> Stashed changes

                }



//                    scanf("%c",&ch);



            }
        }

//            scanf("%c",&ch); //space
        pnode src;
        if (ch == 'B') {
            //printf("ch is: %c\n", ch);

            scanf("%d", &srcNode);
            //src = getNode(head, srcNode);

            insert_node_cmd(&head, srcNode);
            src = getNode(head, srcNode);
            while (scanf("%d", &destNode) != 0 && scanf("%d", &weight) != 0) {

                pnode dest = getNode(head, destNode);


                add_edge(src, dest, weight);
<<<<<<< Updated upstream
=======
                   
>>>>>>> Stashed changes

            }
//            scanf("%c", &ch);

            //printGraph(&head);
        }

//

//            printGraph(&head);
//
        if (ch == 'D') {
            //printf("the is:%c\n", ch);

            scanf("%d", &srcNode);
            //printf("srcNode =%d", srcNode);
            delete_node_cmd(&head, srcNode);
            //printGraph(&head);
        }
//
//
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

            printf("Dijsktra shortest path: %d\n", ans);

        }
//
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


        //scanf("%c", &ch);
    }
    //
    deleteGraph_cmd(&head);

    return 0;
}