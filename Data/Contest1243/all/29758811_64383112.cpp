#include<bits/stdc++.h>

#define ll int
#define ld long double
//#define endl "\n"
#define fi first
#define se second
#define y1 sadjfskldf
#define sqr(asdf) ((asdf) * (asdf))
using namespace std;
const ll N = 5e5 + 200;
const ll LIM = N;
vector<ll> ans[N],v[N];
set<ll> s;
set<ll> :: iterator it;
ll f[N],res,n,m,l,r;
void dfs(ll x)
{
    ans[res].push_back(x);
    s.erase(x);
    f[x] = 1;
    ll l,r;
    for(int i = 1; i < v[x].size(); i++)
    {
        l = v[x][i - 1] + 1;
        r = v[x][i] - 1;
        if(r < l) continue;
        it = s.lower_bound(l);
        while(it != s.end() && *it <= r)
        {
            dfs(*it);
            it = s.lower_bound(l);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i = 1; i <= m; i++)
    {
        cin>>l>>r;
        v[l].push_back(r);
        v[r].push_back(l);
    }
    for(int i = 1; i <= n; i++)
    {
        v[i].push_back(0);
        v[i].push_back(n + 1);
        sort(v[i].begin(), v[i].end());
        s.insert(i);
    }
    for(int i = 1; i <= n; i++) if(!f[i])
    {
        res++;
        dfs(i);
    }
    cout<<res - 1<<endl;
//    for(int i = 1; i <= res; i++)
//    {
//        cout<<ans[i].size();
//        sort(ans[i].begin(), ans[i].end());
//        for(auto x : ans[i]) cout<<" "<<x;
//        cout<<endl;
//    }
    return 0;
}
/*
5 6
......
..*...
.***.*
..*...
..*...

*/
