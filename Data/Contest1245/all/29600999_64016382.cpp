// g++ -std=c++14

/*

Today might be the chance to grasp the chance to let your talent bloom.
May be tomorrow, the day after, or next year...
May be even when you are 30. I'm not sure if physique has anything to do with it
but if you think that it will never come, it probably never will.

- Tooru Oikawa.

*/


#include<bits/stdc++.h>

typedef long long ll;
typedef long double lld;
using namespace std;

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define endl "\n"
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define all(c) c.begin(),c.end()
#define inf 1000000000000000001

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

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

#define int ll

const int N = 2020;

int n;
int x[N], y[N], c[N], k[N];

int dist[N], parent[N];
bool vis[N];
vector<pair<int, int> > g[N], tree[N];

int primsMST(int source) //Finds the cost and makes the MST
{
	for(int i=1;i<=n;i++)
		dist[i]=1e18;
	set<pair<int, int> > s;
	s.insert({0, source});
	int cost=0;
	dist[source]=0;
	while(!s.empty())
	{
		auto x = *(s.begin());
		s.erase(x);
		vis[x.second]=1;
		cost+=x.first;
		int u=x.second;
		int v=parent[x.second];
		int w=x.first;
		tree[u].push_back({v, w});
		tree[v].push_back({u, w});
		for(auto it:g[x.second])
		{
			if(vis[it.first])
				continue;
			if(dist[it.first] > it.second)
			{
				s.erase({dist[it.first], it.first});
				dist[it.first]=it.second;
				s.insert({dist[it.first], it.first});
				parent[it.first]=x.second;
			}
		}
	}
	return cost;
}

int calc(int i, int j) {
    return (abs(x[i] - x[j]) + abs(y[i] - y[j]));
}

int32_t main(){ _
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        g[n + 1].push_back({i, c[i]});
        g[i].push_back({n + 1, c[i]});

    }
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            int dd = calc(i, j);
            dd *= (k[i] + k[j]);
            g[i].push_back({j, dd});
        }
    }
    n++;
    // for (int i = 1; i <= n; i++) {
    //     tr(i, g[i]);
    // }
    cout << primsMST(n) << endl;
    cout << (int)tree[n].size() - 1 << endl;
    for (int i = 0; i < (int)tree[n].size(); i++) {
        int x = tree[n][i].fi;
        if (x != 0) {
            cout << x << " ";
        }
    }
    cout << endl;
    vector<pair<int, int>> ans;
    set<pair<int, int>> ss;
    for (int i = 1; i < n; i++) {
        for (auto j : tree[i]) {
            int p = min(i, j.fi);
            int q = max(i, j.fi);
            if (!ss.count({p, q}) && q != n && p != 0) {
                ans.push_back(mp(p, q));
                ss.insert({p, q});
            }
        }
    }
    cout << (int)ans.size() << endl;
    for (auto i : ans) {
        cout << i.fi << " " << i.se << endl;
    }
}
