/*#include <stdio.h>
int add(int a,int b){
    //int c;
    //c=a+b;
    //return c;
    a++;
    printf("%d\n",a);
}
int main(){
    int num1=10 ,num2=15, sum;
    sum=add(num1,num2);
    printf("%d",num1);//so in parametre passing value of a does not change
    //printf("sum is :%d",sum);
}
    */
//call by address
#include <stdio.h>
void swap(int *x,int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
int main(){
    int num1=10 ,num2=15, sum;
    swap(&num1,&num2);
    printf("num1:%d num2:%d",num1,num2);

}