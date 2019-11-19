#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdint.h>
#include <vector>
#include <string>
#include <map>

using namespace std;


int main()
{
    int  t;
    scanf("%i", &t);
    while (t--)
    {
        int a, b, c, d, k;
        scanf("%i%i%i%i%i", &a, &b, &c, &d, &k);
        int x = (a+c-1)/c;
        int y = (b+d-1)/d;
        if (x + y > k)
            printf("-1\n");
        else
            printf("%i %i\n", x, y);
    }
}
