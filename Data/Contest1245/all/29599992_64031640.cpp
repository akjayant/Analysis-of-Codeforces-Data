#include<bits/stdc++.h>
using namespace std;
 
#define END '\n'
#define int long long
#define pb push_back
#define pii pair<int, int>
#define loop(i, a, b) for(int i = (a); i < (b); i++)
#define loopb(i, b, a) for(int i = (b); i > (a); --i)
 
string alpha = "abcdefghijklmnopqrstuvwxyz";
const int mod = 1e9+7;
const int inf = 2e18+5;
const int nax = 2010;
//
int x[nax], y[nax];
int c[nax];
int k[nax];

vector<vector<int>> g;

int parent[nax];
int cost[nax];
int root(int x){
    while(parent[x] != x){
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

void join(int x, int y){
    int r1 = root(x), r2 = root(y);
    if(r1 == r2) return;

    cost[r2] = min(cost[r1], cost[r2]);
    parent[r1] = r2;
}

map<pii, int> W;
vector<pii> eres;
vector<int> st;

bool visited[nax];
int dfs(int u){
    visited[u] = true;
    int r = u;
    for(auto v : g[u]){
        if(!visited[v]){
            int x = dfs(v);
            if(c[r] > c[x]){
                r = x;
            }
        }
    }
    return r;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("fin.txt", "r", stdin);
        freopen("fout.txt", "w", stdout);
    #endif
    //
    int n; cin >> n;

    loop(i, 0, n) cin >> x[i] >> y[i];
    
    loop(i, 0, n) cin >> c[i];
    loop(i, 0, n) cin >> k[i];

    vector<pair<int, pii>> edge;

    loop(i, 0, n){
        loop(j, i+1, n){
            int cst = k[i]+k[j];
            int dist = abs(x[i]-x[j])+abs(y[i]-y[j]);
            edge.pb({cst*dist, {i, j}});
        }
    }

    loop(i, 0, nax) parent[i] = i;
    loop(i, 0, nax) cost[i] = c[i];

    sort(edge.begin(), edge.end());

    g = vector<vector<int>>(n);

    int res = 0;
    loop(i, 0, n) res += c[i];


    for(auto e : edge){
        int w = e.first;
        int u = e.second.first; int v = e.second.second;
        if(root(u) == root(v)) continue;


        int del = w - max(cost[root(u)], cost[root(v)]);
        if(del > 0) continue;

        res += del;

        g[u].pb(v);
        g[v].pb(u);
        join(u, v);
        W[{u, v}] = W[{v, u}] = w;

        eres.pb({u, v});
    }

    cout << res << END;

    loop(i, 0, n){
        if(!visited[i]){
            st.pb(dfs(i));
        }
    }

    cout << st.size() << END;
    for(auto x : st) cout << x+1 << ' '; 
    cout << END;

    cout << eres.size() << END;
    for(auto x : eres){
        cout << x.first+1 << ' ' << x.second+1 << END;
    }




    return 0;
}