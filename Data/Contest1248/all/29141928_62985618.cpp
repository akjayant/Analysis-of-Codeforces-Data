#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define INF 0x3f3f3f3f
#define ll long long
#define mod 1000000007
#define maxx 100005
using namespace std;
int a[maxx];
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    sort(a+1,a+n+1);
    int x=n/2;
    ll l=0;
    for(int i=1;i<=x;i++)
        l+=a[i];
    ll r=0;
    for(int i=x+1;i<=n;i++)
        r+=a[i];
    printf("%lld\n",(ll)r*r+(ll)l*l);
    return 0;
}