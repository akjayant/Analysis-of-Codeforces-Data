#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int t;
inline int gcd(int n,int m)
{
    return m ? gcd(m,n%m) : n;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        int a,b;scanf("%d %d",&a,&b);
        if(gcd(a,b)==1) puts("Finite");
        else puts("Infinite");
    }
    return 0;
}