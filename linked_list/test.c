#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*first;

int main(){
    struct Node *last;
    
    first=(struct Node *)malloc(sizeof(struct Node));
    if (first==NULL){
        printf("Memory allocation is not possible");
        return 1;

    }
    first->data=20;
    first->next=NULL;
    printf("%d \n",first);
    printf("%d\n",&first->data);
    printf("%d\n",&first->next);
    last=first;

    int A[]={10,20,3,4};
    int i;
    int n=4;
    struct Node *t;
    for (i=0;i<n;i++){
        // printf("%d \n",A[i]);
        t = (struct Node *)malloc(sizeof(struct Node));
        
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last=t;


        printf("%d \n", t);
        printf("Address %d, data %d , next address %d value %d \n", &t->data, t->data, &last->next, last->next);



    }

}