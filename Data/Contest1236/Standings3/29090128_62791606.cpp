#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<cstdio>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
#include<map>
#include<set>
#include<queue>
#include<set>
#define READ                freopen("in.txt", "r", stdin)
#define WRITE               freopen("out.txt", "w", stdout)
#define INF9                1000000010
#define INF18               1000000000000000010
#define dist(ax,ay,bx,by)   sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by))
#define mod                  1000000007
#define gcd(a,b)            __gcd(a,b)
#define lcm(a,b)            (a*b)/__gcd(a,b)
#define m_p(a,b)            make_pair(a,b)
#define sqr(a)              ((a)*(a))
#define pb                  push_back
#define bpll(a)             __builtin_popcountll(a)
#define MX                  100005

using namespace std;
typedef long long lli;

lli bigmod(lli b, lli p, lli m)
{
    b%=m;
    if(p==0) return 1;

    lli ret= bigmod(b, p/2, m);
    ret= (ret*ret)%m;
    if(p%2) return (ret*b)%m;
    return ret;
}



int main()
{
    lli n, m;
    scanf("%lld %lld", &n, &m);

    lli ans= bigmod(2, m, mod)-1;
    ans= (ans+mod)%mod;

    lli res= bigmod(ans, n, mod);
    cout<<res<<endl;



    return 0;
}
