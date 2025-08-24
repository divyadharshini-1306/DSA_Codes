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
int count(struct Node *p)
{
    int l=0;
    while(p)
    {
        l++;
        p=p->next;

    }
    return l;
}

int Rcount(struct Node *p)
{
    if(p!=NULL)
        return Rcount(p->next)+1;
    else
        return 0;
}
int Add(struct Node *p){
    int sum=0;
    while(p){
        sum=sum+p->data;
        p=p->next;
    }
    return sum;
}
int RAdd(struct Node *p){
    if (p==NULL){
        return (0);
    }
    else return RAdd(p->next)+p->data;
}




int main(){
    int A[]={3,5,7,10,15,90,34,56};
    create(A,8); 
    //printf("length is %d ",Rcount(first));         
    printf("sum is %d",RAdd(first));
    return 0;
}