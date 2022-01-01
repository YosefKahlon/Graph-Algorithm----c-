#include <stdio.h>
#include <stdlib.h>
typedef struct edges{
    
    int dest;
    int weight;
    struct edges* next;
}edges;
typedef struct Node{
    int id;
    int data;
    struct Node *next;
    struct edges *edge;
}Node;
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

#define head **p

int main (){
    
    char ch;
    char node;
    scanf("%c",&node);
    // while (ch!='z'){
    //     if(ch=='A')
    //     {
    //         scanf("%d",&node);
    //         if(node>0)
    //         {
    //        head= creatgrph(node);
    //         }

        
        
    //         struct Node **current=head;
    //         while(*current)
    //         {
    //         printf("  %d--> \n",(*current)->id);

    //         current=&((*current)->next);
    //         }
    //     }
    //     scanf("%c",&ch);
    //     if(ch=='n')
    //     {
    //         printf("need to add edge\n");
    //     };
    // }
    printf("%d",node-48);
    
    return 0;
}

// int main(){
//     // struct Node** head=NULL ;
    
//     // struct Node* first =NULL;
//     // struct Node* second =NULL;
//     // struct Node* third =NULL;
 
//     // // allocate 3 nodes in the heap
//     // head = (struct Node**)malloc(sizeof(struct Node));
    
//     // first = (struct Node*)malloc(sizeof(struct Node));
//     // (*head)=first;
    
//     // second = (struct Node*)malloc(sizeof(struct Node));
//     // third = (struct Node*)malloc(sizeof(struct Node));
//     // struct edges* edgeh3=NULL;
//     // edgeh3=(struct edges*)malloc(sizeof(struct edges));
//     // struct edges** heade3=NULL ;
//     // heade3 = (struct edges**)malloc(sizeof(struct edges));
//     // (*heade3)=third->edge;
    
//     // third->id=4;
//     // first->id=1;
//     // first->next=second;
//     // second->id=2;
//     // second->data=5;
//     // second->next=third;
//     // struct edges* edgeh2=NULL;
//     // edgeh2=(struct edges*)malloc(sizeof(struct edges));
//     // struct edges** heade2=NULL ;
//     // heade2 = (struct edges**)malloc(sizeof(struct edges));
//     // (*heade2)=second->edge;
//     // second->edge=edgeh2;
//     // edgeh2->dest=1;
//     // edgeh2->weight=2;
//     // first->data=3;
//     // struct edges* edgeh=NULL;
//     // edgeh=(struct edges*)malloc(sizeof(struct edges));
//     // struct edges** heade=NULL ;
//     // heade = (struct edges**)malloc(sizeof(struct edges));
//     // (*heade)=first->edge;
//     // first->edge=edgeh;
//     // struct edges* edgeh11=NULL;
//     // edgeh11=(struct edges*)malloc(sizeof(struct edges));
//     // first->edge->dest=2;
//     // first->edge->weight=3;
//     // first->edge->next=edgeh11;
//     // first->edge->next->dest=3;
//     // first->edge->next->weight=10;
//     // first->edge->next->next=NULL;
   
    
    
    
//     // struct Node **current=head;
//     // insertLast(37,7,head);
//     // while(*current)
//     // {
//     //     if((*current)->id==37)
//     //     {
//     //         struct edges* edgeh12=NULL;
//     //         edgeh12=(struct edges*)malloc(sizeof(struct edges));
//     //         (*current)->edge=edgeh12; 
//     //         (*current)->edge->dest=4;
//     //         (*current)->edge->weight=10;
               
//     //     }
//     //     printf("%d--> \n  ",(*current)->id);
//     //     struct edges *currente=((*current)->edge);
//     //     // struct edges **currente=(*current)->edge;
//     //     int cuonte =0;
//     //     while(currente){

//     //         cuonte=cuonte+1;
//     //         printf("%d-->%d W:%d\n",(*current)->id,(currente)->dest,(currente)->weight);
//     //         currente=currente->next;
            

//     //     }

        
//     //     current=&((*current)->next);
        
//     // }
    
    
//     // printf("%d--->%d weight:   edge:%d-->%d",second->id,third ->id,(*head)->id,(*head)->edge->dest);
//     return 0;
// }