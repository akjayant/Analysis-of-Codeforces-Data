/**
*
* Author: MARS
* Lang: GNU C++14
*
**/

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ii pair < int , int >
#define LS pair < ll , string >

typedef unsigned long long ull;
typedef long double ldbl;
typedef long long ll;
typedef double dbl;

const ldbl E = 2.71828182845904523536;
const ldbl pi = acos(-1);
const dbl eps = 1e-9;
const ll mod = 1e9+7;
const ll inf = 1LL<<30;

/** /////////// ** Code ** /////////// **/


long long POW_M(long long a,long long p,long long m)
{
    if(p == 0) return 1;
    if(p == 1) return a%m;
    long long x=POW_M(a,p/2,m);
    if( p%2 == 0) return ((x%m)*x)%m;
    return (((x%m) *x%m)*a)%m;
}


int main()
{
    ll n,m;
    scanf("%lld%lld",&n,&m);
    ll ans = (POW_M(2,m,mod)-1+mod)%mod;
    ans = POW_M(ans,n,mod);

    printf("%lld",ans);
    return 0;
}
