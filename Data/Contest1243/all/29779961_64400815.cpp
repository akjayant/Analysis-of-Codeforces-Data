// ref:- https://codeforces.com/contest/920/problem/E

#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll c1=0;
set<ll> s[200001];
set<ll> se;


void dfs(ll x)
{
    assert(se.count(x));
    se.erase(x);
    bool done=true;
    while(done)
    {
        done=false;
        for(auto y : se)
        {
            if(s[x].count(y))
                continue;
            dfs(y);
            done=true;
            break;
        }
    
    }
}
 
int main()
{
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        se.insert(i);
    }
    for(int i=0;i<m;i++)
    {
        ll x,y;
        cin>>x>>y;
        s[x].insert(y);
        s[y].insert(x);
    }
    
    for(int i=1;i<=n;i++)
    {
        if(se.count(i))
        {
            c1++;
            dfs(i);
        }
    }
    cout<<c1-1<<endl;
    
    return 0;
}