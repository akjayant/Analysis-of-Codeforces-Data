#include<bits/stdc++.h>
#define mp make_pair
#define se second
#define fi first
#define pi acos(-1.0)
#define mem(a, b) memset(a, b, sizeof(a))
#define debug(x) cout <<"x" << " = " << x << "\n";
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;

const int N=1e6+300;
const int maxn=20010;
const int INF=0x3f3f3f3f;
const double eps=0.0000001;
const ll mod=1e9+7;
ll  n,m,x,y,z,k,cnt,t,len,q;
int  a[N];
char str[N];

int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        ll lx=0,ly=0,rx=0,ry=0;
        scanf("%lld",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&x);
            if(x%2==0) lx++;
            else ly++;
        }

        scanf("%lld",&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%lld",&x);
            if(x%2==0) rx++;
            else ry++;
        }

        printf("%lld\n",lx*rx+ly*ry);

    }



}
