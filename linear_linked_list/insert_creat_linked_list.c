#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;

    }

}
void Display(struct Node *p)
{
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }

}
int count(struct Node *p){
    int c=0;
    while(p){
        c++;
        p=p->next;
    }
    return c;
}
void Insert(struct Node *p,int index,int x)
{
    struct Node *t;
    int i;
    if(index<0 || index>count(p))
        return ;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    if(index==0)
    {
        t->next=first;
        first=t;
    }
    else
    {
        for(i=0;i<index-1;i++)
            p=p->next;
        t->next=p->next;
        p->next=t;

    }
}
int main(){
    Insert(first,0,15);
    Insert(first,1,12);
    Insert(first,2,17);
    Insert(first,3,10);
    Insert(first,0,13);

    Display(first);

    return 0;

}