#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <math.h>
#include <stdlib.h>
#define mod 1000000007
using namespace std;

long long f[100009];
long long f2[100009];
int main()
{
    f[1]=2;
    f[2]=4;
    f2[1]=2;f2[2]=4;
    for(int i=3;i<=100001;i++)
    {
        f2[i]=(f2[i-1]+f[i-1])%mod;
        f[i]=(f[i-1]+f[i-2])%mod;
    }
    int n,m;
    scanf("%d%d",&n,&m);
    int minn=min(n,m);
    int maxn=max(n,m);
    long long sum=f[n]+f2[m-1];
    printf("%lld\n",sum%mod);
    return 0;
}
