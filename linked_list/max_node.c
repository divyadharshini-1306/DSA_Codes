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
int Max(struct Node *p){
    int max=-32768,MIN_INT;
    while(p){
        if(p->data>max){
            max=p->data;
        p=p->next;

        }
    }
        return(max);
    }
int RMax(struct Node *p){
    int x=0;
    if(p==0)
        return -32678;
    x=max(p->next);
    return x>p->data?x:p->data;

}
int main(){
    int A[]={3,5,7,10,15,8,12,20};
    create(A,8);
    printf("Max is %d",RMax(first));

    return 0;
}