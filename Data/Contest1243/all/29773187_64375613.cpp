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
#define MX                  1300005

using namespace std;
typedef long long lli;


int main()
{
    lli test;
    scanf("%lld", &test);

    for(lli t=1; t<=test; t++)
    {
        vector<lli>ara;
        lli n;
        scanf("%lld", &n);

        for(lli i=0; i<n; i++)
        {
            lli a;
            scanf("%lld", &a);
            ara.push_back(a);
        }

        sort(ara.begin(), ara.end());
        reverse(ara.begin(), ara.end());

        lli ans=0;


        for(lli i=0; i<n; i++)
        {
            if(ara[i]>=i+1) ans=i+1;
        }
        cout<<ans<<endl;

    }

    return 0;
}
