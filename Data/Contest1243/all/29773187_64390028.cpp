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
#define MX                  1000100

using namespace std;
typedef long long lli;

bool mark[1000100+5];
vector<lli>primes;
lli n, m, k;

bool check(lli n)
{
    if(n<2) return false;
    if(n==2) return true;
    if(n%2==0) return false;
    return mark[n]==false;
}

void sieve(lli n)
{
    for(lli i=3; i*i<=n; i+=2)
    {
        if(mark[i]==false)
        {
            for(lli j=i*i; j<=n; j+=2*i) mark[j]=true;
        }
    }
}

vector<lli>v;

int main()
{
   // READ;
    sieve(MX);

    for(lli i=0; i<MX; i++)
    {
        if(check(i)) primes.push_back(i);
    }

    lli n;
    scanf("%lld", &n);

    if(n==1)
    {
        cout<<1<<endl;
        return 0;
    }

    lli temp=n;

    for(lli i=0; primes[i]*primes[i]<=n && i<primes.size(); i++)
    {
        if(temp%primes[i]==0)
        {
            while(temp%primes[i]==0)
            {
                temp/=primes[i];
            }

            v.push_back(primes[i]);
        }
    }

    if(temp>1) v.push_back(temp);

    if(v.size()>1)printf("1\n");
    else printf("%lld\n", v.back());

    return 0;
}
