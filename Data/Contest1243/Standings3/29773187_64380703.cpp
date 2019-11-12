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

string s, t;
char sara[10005];

int main()
{
    lli test;
    scanf("%lld", &test);

    for(lli tst=1; tst<=test; tst++)
    {
        lli n;
        scanf("%lld", &n);

        scanf("%s", &sara);
        s= sara;
        scanf("%s", &sara);
        t= sara;

        vector<lli>idx;

//        cout<<s<<" "<<t<<endl;

        for(lli i=0; i<n; i++)
        {
            if(s[i]!=t[i]) idx.push_back(i);
        }

        if(idx.size()==0)
        {
            printf("Yes\n");
        }
        else if(idx.size()==2)
        {
            lli id1= idx[0];
            lli id2= idx[1];

//            cout<<".."<<endl;
//            cout<<id1<<" "<<id2<<endl;

            if(s[id1]==s[id2] && t[id1]==t[id2]) printf("Yes\n");
            else printf("No\n");
        }
        else printf("No\n");
    }

    return 0;
}
