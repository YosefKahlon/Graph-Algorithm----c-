#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "limits.h"


int *missArr(const int pInt[], int size, int j);


int *tsp_r(pnode pNode, int *pInt, int *pInt1, int i, int min, int i1, int len);


int shortedPath(node **head, int src, int dest, int len) {
    int weight[len];
    int viz[len];
    int tempans = INT_MAX;
    for (int i = 0; i < len; i++) {
        weight[i] = INT_MAX;
        viz[i] = 0;
    }

    if (src == dest) {
        return 0;
    }

    weight[src] = 0;

    int minIndex;
    pnode curr = getNode(*head, src);

    while (curr != NULL) {
        pedge *headEdge = &(*curr).edges;
        viz[curr->node_num] = 2;
        if (curr->node_num == dest) {
            break;
        }
        minIndex = -1;

        int temp = 0;
        while ((*headEdge) != NULL) {
            pnode d = getNode(*head, (*headEdge)->endpoint->node_num);
            pedge e = (*headEdge);
            if (viz[d->node_num] != 2) {


                int w = e->weight;
                temp = w + weight[curr->node_num];


                if (viz[d->node_num] == 0) {
                    viz[d->node_num] = 1;
                }
                if (temp <= weight[d->node_num]) {
                    weight[d->node_num] = temp;
                }

                if (d->node_num == dest) {
                    tempans = weight[d->node_num];
                }


                int min = weight[d->node_num];

                for (int i = 0; i < len; i++) {

                    if (weight[i] <= min && viz[i] == 1) {


                        min = weight[i];
                        minIndex = i;
                    } else if (viz[i] == 1) {
                        weight[i] = INT_MAX;
                    }
                }

                (headEdge) = &((*headEdge)->next);
            }


            if (minIndex == -1 ) {
                (headEdge) = &((*headEdge)->next);

            }

       }

        curr = getNode(*head, minIndex);
    }

    int ans = weight[dest];
    if (minIndex == -1 && tempans != INT_MAX) {
        return tempans;}
    else if (minIndex == -1){
        return  -1;}

    return ans;
}


int azeret(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * azeret(n - 1);

}

int shortedPathForTSP(node **head, int src, int dest, int len) {
    int weight[len];
    int viz[len];
    for (int i = 0; i < len; i++) {
        weight[i] = INT_MAX;
        viz[i] = 0;
    }

    if (src == dest) {
        return 0;
    }

    weight[src] = 0;

    int minIndex;
    pnode curr = getNode(*head, src);


    while (curr != NULL) {
        pedge *headEdge = &(*curr).edges;
        viz[curr->node_num] = 2;
        if (curr->node_num == dest) {
            break;
        }
        minIndex = -1;

        int temp = 0;
        while ((*headEdge) != NULL) {
            pnode d = getNode(*head, (*headEdge)->endpoint->node_num);
            pedge e = (*headEdge);
            if (viz[d->node_num] != 2) {
                int w = e->weight;
                temp = w + weight[curr->node_num];

                if (viz[d->node_num] == 0) {
                    viz[d->node_num] = 1;
                }
                if (temp <= weight[d->node_num]) {
                    weight[d->node_num] = temp;
                }

                int min = weight[d->node_num];
                for (int i = 0; i < len; i++) {

                    if (weight[i] <= min && viz[i] == 1) {
                        min = weight[i];
                        minIndex = i;
                    } else if (viz[i] == 1) {
                        weight[i] = INT_MAX;
                    }
                }
            }
            (headEdge) = &((*headEdge)->next);
        }

        if (minIndex == -1) {
            return (INT_MAX / 2);
        }

        curr = getNode(*head, minIndex);
    }
    int ans = weight[dest];

    return ans;
}


void TSP(pnode *head, int list[], int size, int max) {

    if (size > 1) {


        int factorial = azeret(size);

        int *optionAns = (int *) malloc(sizeof(int) * factorial);
        if (optionAns == NULL) {
            exit(1);
        }

        int counter = 0;

//        int *num = (int *) malloc(sizeof(int) * size);
//        if (num == NULL) {
//            exit(1);
//        }

        int num[size];
        int temp;
        int i;
        int n = size;
        int j;
        int temp_weight = 0;

        printf("\nEnter a list of numbers to see all combinations:\n");
        for (i = 0; i < n; i++) {
            num[i] = list[i];
        }


        for (j = 1; j <= n; j++) {
            for (i = 0; i < n - 1; i++, counter++) {
                temp = num[i];
                num[i] = num[i + 1];
                num[i + 1] = temp;

                for (int left = 0; left < n - 1; left++) {
                    int right = left + 1;

                    int shortest = shortedPath(head, num[left], num[right], max);
                    printf("shortest= %d from: %d to: %d\n", shortest, num[left], num[right]);
                    if (shortest == -1) {
                        optionAns[counter] = INT_MAX;
                        printf("--- inside %d\n", optionAns[counter]);
                        temp_weight = 0;
                        counter++;

                        break;
                    }
                    temp_weight = temp_weight + shortest;


                }
                optionAns[counter] = temp_weight;
                printf("--- outside %d\n", optionAns[counter]);
                temp_weight = 0;


            }


        }



        printf("\n");
        int min = INT_MAX;
        for (int k = 0; k < counter; k++) {
            if (optionAns[k]!=0&&optionAns[k] < min) {
                min = optionAns[k];
            }
        }

        printf("TSP shortest path: %d\n", min);

        free(optionAns);
       // free(num);



    } else {
        printf("TSP shortest path: %d\n", 0);

    }


}







