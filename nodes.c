#include<stdio.h>
#include <stdlib.h>
typedef struct Node{
    int id;
    int data;
    struct Node *next;
    struct edges *edge;
}Node;
typedef struct edges{
    
    int dest;
    int weight;
    struct edges* next;
}edges;
 
Node* newNode(int id,int data, Node *next) {
Node *p = (Node*) malloc (sizeof(Node));
struct edges* edgeh3=NULL;
edgeh3=(struct edges*)malloc(sizeof(struct edges));
    struct edges** heade3=NULL ;
    heade3 = (struct edges**)malloc(sizeof(struct edges));
    
p->data = data;
p->next = next;
(*heade3)=p->edge;
p->id=id;
return p;
}
void insertLast(int id,int data, struct Node **head) {
struct Node **p = head;
while(*p)
p = &((*p)->next);
*p = newNode(id,data,NULL);
}


Node** creatgrph(int k){
    
    struct Node** head=NULL ;
    head = (struct Node**)malloc(sizeof(struct Node));
    int i=0;
    if(k>0)
    {
    
        while(i!=k)
        {
        insertLast(i,0,head);
            i=i+1;
        }
    }

    
    return head ;
 }
int main (){
    struct Node** head=NULL ;
    head = (struct Node**)malloc(sizeof(struct Node));
    int ch;
    int node;
    scanf("%d",&ch);
    if(ch=='A'){
        
        if(ch>0){
           head= creatgrph(node);
        }

        
    }
    struct Node **current=head;
    
    while(*current)
    {
        
        
        printf("%d--> \n  ",(*current)->id);
        

        
        current=&((*current)->next);
    }
    return 0;
}









