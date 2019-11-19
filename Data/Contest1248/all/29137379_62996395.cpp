#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const ll MAXN = 2e5+10;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

ll n,m;
ll ff[MAXN];
void init()
{
    ff[1] = 2;
    ff[2] = 4;
    for(int i=3;i<=MAXN - 5;i++)
        ff[i] = (ff[i-1]+ff[i-2])%mod;
}
int main()
{
    scanf("%lld%lld",&n,&m);
    init();
    printf("%lld\n",(ff[n]+ff[m]-2)%mod);
}
