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
ll  a[N];
char str[N];

int main()
{
    scanf("%lld",&n);
    ll cnt=0;
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]),cnt+=a[i];
    sort(a+1,a+1+n);
    int len=n/2;
    ll sum=0;
    for(int i=1;i<=len;i++)
    {
        sum+=a[i];
    }
    printf("%lld\n",sum*sum+(cnt-sum)*(cnt-sum));



}
