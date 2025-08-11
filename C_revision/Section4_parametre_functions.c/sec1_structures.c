#include <stdio.h>
struct Rectangle
{
    int length;
    int breadth;
    char x;
};//r1,r2,r3;   //gloabal varaible
//struct Rectangle r1;

int main()
{
    struct Rectangle r1={10,5};
    r1.length=15;
    r1.breadth=7;
    //printf("%lu",sizeof(r1));
    printf("%lu\n",r1.length);
    printf("%lu",r1.breadth);



}