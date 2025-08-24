#include <stdio.h>
#include <stdlib.h>

struct Node
{   int data;
    struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

void Display(struct Node *p)
{
    while(p!=0)
    {
    printf("%d ",p->data);
    p=p->next;
    }
}

void create1(int A[],int n)
{
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node *));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }


}

void create2(int B[],int n)
{
    struct Node *t,*last;
    second=(struct Node *)malloc(sizeof(struct Node));
    second->data=B[0];
    second->next=NULL;
    last=second;

    for(int i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node*));
        t->data=B[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }


}
void Merge(struct Node *p,struct Node *q)
{
    struct Node *last;
    if(p->data<q->data)
    {
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else
    {
        third=last=q;
        q=q->next;
        third->next=NULL;

    }
    while(p && q)
    {
        if(p->data<q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p)last->next=p;
    if(q)last->next=q;
}
int main()
{
    int A[]={10,20,30,40,50};
    int B[]={100,90,80,70,60};
    create1(A,5);
    create2(B,5);
    Merge(first,second);
    Display(third);

}