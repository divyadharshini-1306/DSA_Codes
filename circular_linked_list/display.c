#include <stdio.h>
#include <stdlib.h>

struct Node
{   int data;
    struct Node *next;
}*Head;

void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    Head=(struct Node *)malloc(sizeof(struct Node));
    Head->data=A[0];
    Head->next=Head; //Making it circular
    last=Head;

    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;

    }

}


void Display(struct Node *h)
{do {
    printf("%d ",h->data);
    h=h->next;
}while(h!=Head);
printf("\n");
}


void Rdisplay(struct Node *h)
{
    static int flag=0;
    if(h!=Head || flag==0)
    {

        flag=1;
        printf("%d ",h->data);
        Rdisplay(h->next);

    }
    
    flag=0;
}

int main()
{/*
    int A[100];
    int n,i;
    printf("Enter the elements of the array: ");
    scanf("%d",&n);

    printf("enter %d elements:\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);

    }
    printf("You have entered: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
        */

    int A[]={2,3,4,5};
    create(A,5);
    Display(Head);
    Rdisplay(Head);


}
