#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[],int n)
{
    struct Node *t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    int i;
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
    if(p!=0){
        printf("%d ",p->data);
        p=p->next;
    }
}
void RDisplay(struct Node *p)
{
    if(p!=NULL)
    {
    RDisplay(p->next);
    printf("%d ",p->data);

    }

}
int count(struct Node *p)
{
    int c=0;
    while(p!=NULL)
    {
        c++;
        p=p->next;

    }
    return c;

}
int Delete(struct Node *p,int index)
{
    struct Node *q=NULL;
    int x=-1,i;

    if(index<1 ||index>count(p))
        return -1;
    if(index==1) //special case deleting the first node
    {
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;

    }
    else
    {
        for(i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;

    }
}
int main()
{
    int A[]={10,20,30,40,50};
    create(A,5);

    printf("%d\n",Delete(first,1));
    Display(first);
}
