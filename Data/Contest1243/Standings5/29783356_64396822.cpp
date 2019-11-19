    #include <bits/stdc++.h>
    #include <cstdio>
    #include <cstring>
    #include <cmath>
    #include <cstring>
    #include <chrono>
    #include <complex>
    #define endl "\n"
    #define ll long long int
    #define vi vector<int>
    #define vll vector<ll>
    #define vvi vector < vi >
    #define pii pair<int,int>
    #define pll pair<long long, long long>
    #define mod 1000000007
    #define inf 1000000000000000001;
    #define all(c) c.begin(),c.end()
    #define mp(x,y) make_pair(x,y)
    #define mem(a,val) memset(a,val,sizeof(a))
    #define eb emplace_back
    #define fi first
    #define se second
#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define pb(x) push_back(x)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

    using namespace std;

template<typename S, typename T>
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
ll l=v.size();for(ll i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

    set<ll> adj[200000];
    ll n,m;
    set<ll> vis;
    multiset<ll> ans;
    void dfs1util(ll s, ll &siz){
        vis.erase(s);
        siz++;
        ll cur = 0;
        while (1) {
            auto it = vis.upper_bound(cur);
            if (it == vis.end()) break;
            cur = *it;
            if (adj[s].find(*it) == adj[s].end()) 
                dfs1util(*it, siz);
        }
    }
    void dfs1(){
        while (!vis.empty()) {
            ll siz = 0;
            dfs1util(*(vis.begin()), siz);
            ans.insert(siz);
        }
    }
    int main()
    {_

        cin >> n >> m;
        for(ll i = 0 ; i < m ; i++){
            ll u,v;
            cin >> u >> v;
            u--;v--;
            adj[u].insert(v);
            adj[v].insert(u);

        }
        for(ll i = 0 ; i < n ; i++)
            vis.insert(i);
        dfs1();
        cout << ans.size() - 1 << endl;
        return 0;
        
    }
// http://codeforces.com/problemset/tags/dp/page/3?order=BY_SOLVED_DESC