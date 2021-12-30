#include<stdio.h>
typedef struct edges{
    
    int dest;
    int weight;
    struct edges* next;
}edges;