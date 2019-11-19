// g++ -std=c++14

#include <bits/stdc++.h>

typedef long long ll;
typedef long double lld;
typedef long long int lli;
using namespace std;
const int N = 1000001;
const bool DEBUG = 1;

#define sd(x) scanf("%d", &x)
#define sd2(x, y) scanf("%d%d", &x, &y)
#define sd3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define endl "\n"
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define LET(x, a) __typeof(a) x(a)
#define foreach(it, v) for (LET(it, v.begin()); it != v.end(); it++)
#define MEMS(a, b) memset(a, b, sizeof(a))
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);


#define int ll

map<int,vector<int>>g1,tree1;
// __builtin_popcount -> count number of bits
int dist[N], parent[N];
bool vis[N];
vector<pair<int, int> > g[N], tree[N];

int n,u,v1;
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
void print_tree(){
    int len =tree[n].size() - 1;
    cout<<len<<endl;
    len+=1;
    for (int i = 0; i < len; i++) {
        if (tree[n][i].fi) {
            cout << tree[n][i].fi << " ";
        }
    }
    vector<pair<int, int>> ans;
    set<pair<int, int>> st;
    cout << endl;
    for (int i = 1; i < n; i++) {
        for (auto j : tree[i]) {
            int p = min(i, j.fi);
            int q = max(i, j.fi);
            if (!st.count({p, q}) && q != n && p != 0) {
                ans.pb(mp(p, q));
                st.insert({p, q});
            }
        }
    }
    int p=ans.size();
    cout << p << endl;
    for (auto t : ans) {
        cout << t.fi << " " << t.se << endl;
    }
}
int32_t main() {
    cin>>n;
    vector<pair<int,int>>v;
    v.pb(mp(0,0));
    for(int i=1;i<=n;i++){
        cin>>u>>v1;
        v.pb(mp(u,v1));
    }
    int c[n+1],k[n+1];
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int w=abs(v[i].fi-v[j].fi)+abs(v[i].se-v[j].se);
            g[i].push_back({j, w*(k[i]+k[j])});
            g[j].push_back({i, w*(k[i]+k[j])});
        }
    }
    for(int i=1;i<=n;i++){
        g[n+1].push_back({i, c[i]});
        g[i].push_back({n+1, c[i]});
    }
    n++;
    int ans =primsMST(n);
    cout<<ans<<endl;
    print_tree();
    // sort(v1.begin(),v1.end());


}
