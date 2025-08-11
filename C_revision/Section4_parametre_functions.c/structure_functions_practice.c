#include <stdio.h>
struct Rectangle{
    int length;
    int breadth;
};
void intialize(struct Rectangle *r,int l,int b){
    r->length=l;
    r->breadth=b;
}
int area(struct Rectangle r)
{
    return r.length*r.breadth;
}
void changelength(struct Rectangle *r,int l){
    r->length=l;
}
int main(){
    struct Rectangle r;
    intialize(&r,10,5);
    printf("Initial Area: %d\n", area(r));
    changelength(&r,20);
    printf("New area:%d\n",area(r));
}
