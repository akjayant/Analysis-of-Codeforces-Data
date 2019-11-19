#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

#define pb push_back
#define mp make_pair
#define taskname "A"

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef tree <int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int maxn = 1e5 + 5;
vector<int> adj[maxn];
int n;
ll dp[maxn][3][3];
int c[maxn][3];
vector<int> road;

void DFS(int u , int par){
    int child = 0;
    road.pb(u);
    for(int c : adj[u]){
        if(c == par)continue;
        DFS(c , u);
        child++;
    }
    if(child > 1){
        cout << -1;
        exit(0);
    }
}

ll res = 1e18;
int color[maxn];
void Go(int i , int j , bool Print){
    int pre = i;
    int now = j;
    ll ans = 0;
    for(int t = 0 ; t < n ; ++t){
        if(t >= 2){
            int tmp = now;
            now = 3 - now - pre;
            pre = tmp;
            ans += c[road[t]][now];
            color[road[t]] = now;
        }else if(t == 0){
            ans += c[road[t]][i];
            color[road[t]] = i;
        }else if(t == 1){
            ans += c[road[t]][j];
            color[road[t]] = j;
        }
    }
    res = min(ans , res);
    if(Print == 1 && res == ans){
        cout << res << '\n';
        for(int i = 1 ; i <= n ; ++i)cout << color[i] + 1 << " ";
        exit(0);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(taskname".INP","r")){
		freopen(taskname".INP", "r",stdin);
		freopen(taskname".OUT", "w",stdout);
    }
    cin >> n;
    for(int j = 0 ; j < 3 ; ++j){
        for(int i = 1 ; i <= n ; ++i)cin >> c[i][j];
    }
    for(int i = 1 ; i < n ; ++i){
        int u , v;cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int root = 0;
    for(int i = 1 ; i <= n ; ++i){
        if(adj[i].size() == 1){
            root = i;
            DFS(i , 0);
            break;
        }
    }
//    cout << road.size() << endl;
    for(int i = 0 ; i < 3 ; ++i){
        for(int j = 0 ; j < 3 ; ++j){
            if(i == j)continue;
            Go(i , j , 0);
        }
    }
    for(int i = 0 ; i < 3 ; ++i){
        for(int j = 0 ; j < 3 ; ++j){
            if(i == j)continue;
            Go(i , j , 1);
        }
    }
}

