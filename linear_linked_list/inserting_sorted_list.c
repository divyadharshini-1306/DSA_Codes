#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*first=NULL;*second=NULL,*third=NULL;

void create(int A[],int n){
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;

    }
}

void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
void SortedInsert(struct Node *p,int x){
    struct Node *t,*q=NULL; //tracing pointer
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if(first==NULL)
    {
        first=t; //incase first node does not exist
    }
    else
    {
        while(p && p->data<x)
        {
            q=p;       //tracing to that node
            p=p->next;

        }
        if(p==first)
        {
            t->next=first; //creating the first node
            first=t;

        }
        else{
            t->next=q->next; //inserting the node
            q->next=t;
        }

    }

}
int main(){
    int A[]={10,20,30,40,50};
    create(A,5);
    printf("%d\n",SortedInsert(first,15));
    Display(first);

    return 0;


}