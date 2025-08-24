#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;

}*first;
void create(int A[],int n)
{
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node ));
    first->data=A[0];
    first->next=NULL;
    last=first;
    int i;
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
    while(p!=0)
    {
        printf("%d ",p->data);
        p=p->next;

    }
}
int count(struct Node *p)
{
    int count=0;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;

}
void Reverse1(struct Node *p) //Reversing the elements
{
    int *A,i=0;
    struct Node *q=p;
    A=(int *)malloc(sizeof(int)*count(p));
    while(q!=NULL)
    {
        A[i]=q->data;
        q=q->next;
        i++;

    }
    q=p;
    i--;
    while(q!=NULL)
    {
        q->data=A[i];
        q=q->next;
        i--;
    }


}
void Reverse2(struct Node *p) //Reversing using sliding pointers
{
    struct Node *q=NULL,*r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;

}
void Reverse3(struct Node *q,struct Node *p)
{
    if(p)
    {
        Reverse3(p,p->next);
        p->next=q;
    }
    else
        first=q;
}
int main()
{
    int A[]={10,20,40,50,60};
    create(A,5);
    Reverse1(first);
    Display(first);
    printf("\n");

    Reverse2(first);
    Display(first);
    printf("\n");
    
    Reverse3(NULL,first);
    Display(first);
    printf("\n");

    return 0;
}