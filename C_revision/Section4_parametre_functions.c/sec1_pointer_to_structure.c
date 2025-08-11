#include <stdio.h>
#include <stdlib.h>
struct Rectangle
{
    int length;
    int breadth;
};
int main(){
    //struct Rectangle r={10,5};
    //printf("%d\n",r.length);
    //printf("%d",r.breadth);
     struct Rectangle *p;
     p=(struct Rectangle*)malloc(sizeof(struct Rectangle));
     p->length=10;
     p->breadth=5;
     //in case you wanna take user input
     //printf("Enter the length and breadth\n");
     //scanf("%d %d",&p->length,&p->breadth);
     printf("length: %d\n",p->length);
     printf("Breadth:%d\n",p->breadth);
     free(p);
     return 0;
    }
