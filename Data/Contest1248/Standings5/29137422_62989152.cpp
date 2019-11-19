#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

int n;
ll num[101000];
int main()
{
    scanf("%d",&n);
    for(register int i=1;i<=n;i++) scanf("%lld",&num[i]);
    sort(num+1,num+n+1);
    ll x=0,y=0;
    for(register int i=1;i<=n/2;i++) x+=num[i];
    for(register int i=n/2+1;i<=n;i++) y+=num[i];
    printf("%lld",x*x+y*y);
    return 0;
}