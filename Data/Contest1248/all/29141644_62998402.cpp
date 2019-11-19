#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=1e6+10;
const int MOD=1e9+7;

ll fib[MAXN];

int main()
{
    fib[2]=2;
    fib[3]=2;
    for(int i=4;i<=100000;i++)
        (fib[i]=fib[i-1]+fib[i-2])%=MOD;
    int n,m;
    scanf("%d%d",&n,&m);
    ll ans=2;
    for(int i=2;i<=n;i++)
        (ans+=fib[i])%=MOD;
    for(int i=2;i<=m;i++)
        (ans+=fib[i])%=MOD;
    printf("%lld",ans);
    return 0;
}
