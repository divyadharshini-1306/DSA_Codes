#include <stdio.h>
int survivor(int n,int k);
int survivor(int n,int k)
{
    if(n==1)
        return 0;
    else
        return(survivor(n-1,k)+k)%n;

}
int main()
{
    int n,k;
    printf("Enter the value of n and k\n");
    scanf("%d%d",&n,&k);
    printf("The survivor %d is ",survivor(n,k));
    return 0;
}
