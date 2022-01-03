#include<stdio.h>


typedef struct Node
{
int data;
struct Node* next;
}Node;



Node* newNode(int data, Node *next){
Node *p =(Node*)malloc(sizeof(Node));
p->data = data
*(p)=data





}





int main(){

struct Node node = {0};
node.data = 5;
struct Node node1={0};
node1.data=6;
struct Node node2={0};
node2.data=7;

node.next=&node1;
node1.next=&node2;
 

printf("%d\n",node.next->next->data);
return 0;


}


