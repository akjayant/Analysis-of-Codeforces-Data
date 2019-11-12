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
lli cnt[26];
vector<pair<lli, lli> >ans;

void rset()
{
    ans.clear();
    for(lli i=0; i<26; i++)
    {
        cnt[i]=0;
    }
}

bool valid()
{
    for(lli i=0; i<26; i++)
    {
        if(cnt[i]%2) return false;
    }
    return true;
}

int main()
{
    lli test;
    scanf("%lld", &test);

    for(lli tst=1; tst<=test; tst++)
    {
        rset();
        lli n;
        scanf("%lld", &n);

        scanf("%s", &sara);
        s= sara;
        scanf("%s", &sara);
        t= sara;

        for(lli i=0; i<n; i++)
        {
            cnt[s[i]-'a']++;
        }


        for(lli i=0; i<n; i++)
        {
            cnt[t[i]-'a']++;
        }

        if(valid())
        {
            printf("Yes\n");

            for(lli i=0; i<n; i++)
            {
                if(s[i]==t[i]) continue;
                char ch= s[i];

                bool found= false;

                for(lli j=i+1; j<n; j++)
                {
                    if(s[j]==ch)
                    {
                        swap(t[i], s[j]);
                        ans.push_back({j+1,i+1});
//                        printf("%lld %lld\n", j+1, i+1);
                        found=true;
                        break;
                    }
                }

                if(!found)
                {
                    for(lli j=i+1; j<n; j++)
                    {
                        if(t[j]==ch)
                        {
                            swap(s[n-1],t[j]);
                            ans.push_back({n, j+1});
//                            printf("%lld %lld\n", n, j+1);

                            swap(s[n-1], t[i]);
                            ans.push_back({n, i+1});
                            break;
//                            printf("%lld %lld\n", n, i+1);
                        }
                    }
                }
            }
//            ans.push_back({1,1});

            printf("%lld\n", (lli)ans.size());

            for(lli i=0; i<ans.size(); i++)
            {
                printf("%lld %lld\n", ans[i].first, ans[i].second);
            }
        }
        else printf("No\n");


    }

    return 0;
}
