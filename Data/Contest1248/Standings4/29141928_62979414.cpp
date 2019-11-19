#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define INF 0x3f3f3f3f
#define ll long long
#define mod 1000000007
using namespace std;
int a[2];
int b[2];
int n,m;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        int x;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            a[x&1]++;
        }
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&x);
            b[x&1]++;
        }
        ll ans=(ll)a[0]*b[0]+(ll)a[1]*b[1];
        printf("%lld\n",ans);
    }
    return 0;
}