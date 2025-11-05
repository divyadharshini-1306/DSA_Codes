#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}*first=NULL;

void create(int A[],int n)
{
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node ));
    first->data=A[0];
    first->next=first->prev=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->prev=last;
        //t->next=NULL;
        t->next=last->next;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *p)
{
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

int Length(struct Node *p)
{
    int len=0;
    while(p)
    {
        len++;
        p=p->next;
    }
    return len;
}
int Delete(struct Node *p,int index)
{
    //struct Node *q;
    int x=-1,i;
    if(index<1 ||index>Length(p))
        return -1; //index is invalid
    if(index==1)
    {
        first=first->next;
        if(first)first->prev=NULL;
        x=p->data;
        free(p);
        return x;


    }
    else
    {
        for(i=0;i<index-1;i++)
        {
            p=p->next;
        p->prev->next=p->next;
        if(p->next)
            p->next->prev=p->prev;
        x=p->data;
        free(p);
        }
        return x;
    }

}


int main()
{
    int A[]={10,20,30,40,50};
    create(A,5);
    printf("\nLength is :%d \n",Length(first));
    Delete(first,1);
    Display(first);
}