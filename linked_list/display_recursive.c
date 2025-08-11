#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*first;  //making this a global variable

void create(int A[],int n){ //first node creation
    int i;
    struct Node *t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++)//traversing linked list
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void RDisplay(struct Node *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->data);
        RDisplay(p->next);
    }


}




int main(){
    int A[]={3,5,7,10,15};//reversing a linked list
    create(A,5);          //RDisplay(first);
    RDisplay(first);      //create(A,5);  
    
    return 0;
}