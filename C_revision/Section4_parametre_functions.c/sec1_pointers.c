#include <stdio.h>
#include <stdlib.h>
int main(){
//int a=10;
//int *p; //declaration
//p=&a; //intialiisation
//printf("using pointer %d %d",*p &a);//p will give address
//int A[5]={2,4,6,8,10};
int *p; //in stack
/////p=A;//&not required or A[0]
p=(int *)malloc(5*sizeof(int));//in heap
p[0]=10;
p[1]=13;
p[2]=12;
p[3]=14;
p[4]=16;

//using normal
//(int i=0;i<5;i++){
    //printf("%d ",A[i]);
//}
printf("\n");
for(int i=0;i<5;i++){
    printf("%d ",*(p+i));
}
free(p);//deallocating memory in heap
//printf("\n");
}