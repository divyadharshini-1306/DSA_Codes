#include <stdio.h>
#include <stdlib.h>
struct Rectangle
{
    int length;
    int breadth;
};
void fun(struct Rectangle r){
    
}
int main(){
    struct Rectangle r={10,5};
    printf("Length %d\n Breadth %d\n",r.length,r.breadth);
    return 0;
}