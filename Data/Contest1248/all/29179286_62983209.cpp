
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
const int mod=1e9+7;
typedef long long ll;

const double eps=10e-8;
const double pi=acos(-1.0);
const int inf=0x3f3f3f3f;
const long long INF=0x3f3f3f3f3f3f3f3f;
typedef pair<ll,ll> pII;
typedef pair<int,int> pii;
typedef pair<int,ll> piI;


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        int a1=0,b1=0,a2=0,b2=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            if(x%2)a1++;
            else b1++;
        }
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            int x;
            scanf("%d",&x);
            if(x%2)a2++;
            else b2++;
        }
        printf("%lld\n",1ll*a1*a2+1ll*b1*b2);
    }

    return 0;
}

