#include<stdio.h>
#include<string.h>
#include "graph.h"
int main() {


    node *head = NULL;


    // int i = 0;
    // int j = 0;
    // char graphc[100] = "A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 n 3 T 3 2 1 3 B 5 0 4 2 1 B 2 1 3 5 1 T 3 2 1 3 D 2 T 2 3 0";
    // char graph[100] = "";
    char ch='0';
    int numOfNode;


    while(ch!= EOF) {


        if (scanf("%c", &ch) != 0 && ch == 'A') {

            deleteGraph_cmd(&head);

            scanf("%d", &numOfNode);

            build_graph_cmd(&head, numOfNode); // build the node

        }


            scanf("%c",&ch);
            while (scanf("%c",&ch)!=0 && ch== 'n') {

                int srcNode;
                scanf("%d",&srcNode);
                pnode src = getNode(head, srcNode);
                int destNode;
                int weight;

                while (scanf("%d",&destNode)!=0 && scanf("%d",&weight)!=0) {

                    pnode dest = getNode(head, destNode);


                    add_edge(src, dest, weight);

                }



//                    scanf("%c",&ch);



                }


//
//            if (graph[i] == 'B') {
//                i++;
//                pnode src;
//                int id = (int) graph[i] - '0';
//                insert_node_cmd(&head, id);
//                src = getNode(head, id);
//                i++;
//
//                while (!(graph[i] >= 'A' && graph[i] <= 'Z') && !(graph[i] >= 'a' && graph[i] <= 'z') &&
//                       graph[i] != '\0') {
//
//                    pnode dest = getNode(head, (int) (graph[i] - '0'));
//                    i++;
//                    int weight = (int) (graph[i] - '0');
//                    i++;
//
//                    add_edge(src, dest, weight);
//                }
//
//            }
//            printGraph(&head);
//
//            if (graph[i] == 'D') {
//                i++;
//                int id = (int) graph[i] - '0';
//                delete_node_cmd(&head, id);
//                i++;
//            }
//
//
//            if (graph[i] == 'S') {
//                i++;
//                pnode src = getNode(head, graph[i] - '0');
//                i++;
//                pnode dest = getNode(head, graph[i] - '0');
//
//                int max = 0;
//                for (pnode curr = head; curr != NULL; curr = curr->next) {
//
//                    if (curr->node_num > max) {
//                        max = curr->node_num;
//                    }
//
//
//                }
//                int len = max + 1;
//
//                int ans = shortedPath(&head, src->node_num, dest->node_num, len);
//
//                printf("dijkstra ans %d\n", ans);
//                i++;
//            }
//
//            if (graph[i] == 'T') {
//                i++;
//                int size = graph[i] - '0';
//                i++;
//                int list[size];
//                for (int k = 0; k < size; k++) {
//                    pnode curr = getNode(head, graph[i] - '0');
//                    list[k] = curr->node_num;
//                    i++;
//                }
//
//
//                TSP(&head, list, size, 5);
//                i++;
//            }
//
//

       scanf("%c",&ch);
   }
    printGraph(&head);

    return 0;
}