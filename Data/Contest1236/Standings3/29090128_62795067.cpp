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

vector<lli>ara[305];

int main()
{
    lli n;
    scanf("%lld", &n);

    for(lli i=0; i<n; i++)
    {
        if(i%2)
        {
            for(lli j=1; j<=n; j++)
            {
                ara[j].push_back(i*n+j);
            }
        }
        else
        {
            for(lli j=1; j<=n; j++)
            {
                ara[j].push_back(i*n+(n-j+1));
            }
        }
    }

    for(lli i=1; i<=n; i++)
    {
        for(lli j=0; j<n; j++) printf("%lld ", ara[i][j]);
        printf("\n");
    }

    return 0;
}
