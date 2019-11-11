#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>

using namespace std;
int GCD(int a,int b)
{
    if(b==0) return a;
    return GCD(b,a%b);
}
int main()
{
    int T,a,b;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&a,&b);
        if(GCD(a,b)==1) printf("Finite\n");
        else printf("Infinite\n");
    }

    return 0;
}

