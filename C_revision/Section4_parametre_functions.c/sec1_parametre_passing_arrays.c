#include <stdio.h>

void fun(int A[], int n){
    printf("Length = %d\n", n);
}

int main()
{
    int A[] = {2, 4, 6, 8, 10};
    int n = sizeof(A) / sizeof(A[0]);

    fun(A, n);

    for(int i = 0; i < n; i++) {
        printf("%d\n", A[i]);
    }

    return 0;
}
