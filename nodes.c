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


Node** creatgrph(int numnode){
    
    struct Node** head=NULL ;
    head = (struct Node**)malloc(sizeof(struct Node));
    int i=0;
    if(numnode>0)
    {
    
        while(i!=numnode)
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
    char ch;
    int node;
    int numOfNodes;
    scanf("%c",&ch);
    while (ch!='z'){
        if(ch=='A')
        {
            scanf("%d",&node);
            numOfNodes=node;
            if(node>0)
            {
           head= creatgrph(node);
            }

        
        
            struct Node **current=head;
            while(*current)
            {
            printf("  %d--> \n",(*current)->id);

            current=&((*current)->next);
            }
        }
        scanf("%c",&ch);
        while(ch=='n')
        {
            
            

            char nodeEdge;
            int true=1;
            
           
               scanf("%c",&nodeEdge);
               struct Node **current2=head;
            while(*current2)
                {
                   char weightu=0;
                   char destu=0;
                   printf("%c",nodeEdge);
                   if((*current2)->id==(nodeEdge))
                        printf("\n%d",nodeEdge);
                    {
                        

                        while(destu!='n')
                        {
                            scanf("%c",&destu);

                            scanf("int",&weightu);
                            weightu==weightu;
                            destu=destu-48;
                            
                            struct edges* edgeh12=NULL;
                            edgeh12=(struct edges*)malloc(sizeof(struct edges));
                            (*current2)->edge=edgeh12; 
                            (*current2)->edge->dest=destu;
                            (*current2)->edge->weight=weightu;
                            printf("\n%d-->%d W:%d\n",(*current2)->id,(*current2)->edge->dest,(*current2)->edge->weight);
                             
                            
                        
                          
                        };
                        printf("------------------------------------------");
                        
                        
                    };
                    current2=&((*current2)->next);
                    
                };
                
              
           
            scanf("%c",&nodeEdge);
            
        };
    }
    return 0;
}









