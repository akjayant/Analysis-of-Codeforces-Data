
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
const int mod=1e9+7;
typedef long long ll;
//typedef __int128 LL;
const double eps=10e-8;
const double pi=acos(-1.0);
const int inf=0x3f3f3f3f;
const long long INF=0x3f3f3f3f3f3f3f3f;
typedef pair<ll,ll> pII;
typedef pair<int,int> pii;
typedef pair<int,ll> piI;

ll a[MAXN];
int main()
{

    int n;

    scanf("%d",&n);
    ll sum=0,sum1=0,sum2=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    sort(a+1,a+1+n);
    n/=2;
    for(int i=1;i<=n;i++)
    {
        sum1+=a[i];
    }
    ll ans=sum1*sum1+(sum-sum1)*(sum-sum1);
    printf("%lld\n",ans);

    return 0;
}