#include "stdio.h"
#include "algorithm"
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        int d = std::__gcd(a, b); 
        if (d == 1)
            printf("Finite\n");
        else printf("Infinite\n");
    }   
}
