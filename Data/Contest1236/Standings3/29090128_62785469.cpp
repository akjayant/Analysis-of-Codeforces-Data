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


int main()
{
    lli test;
    scanf("%lld", &test);

    for(lli t=1; t<=test; t++)
    {
        lli a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);

        lli temp= min(c/2, b);
        lli ans= temp*3;

        b-=temp;

        temp= min(a, b/2);
        ans+= (temp*3);

        cout<<ans<<endl;
    }



    return 0;
}
