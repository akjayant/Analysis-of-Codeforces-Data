#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
    int q;
    scanf("%i", &q);
    while (q--)
    {
        int a, b;
        scanf("%i%i", &a, &b);
        int c = gcd(a, b);
        if (c != 1)
            printf("Infinite\n");
        else
            printf("Finite\n");
    }
}
