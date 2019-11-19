#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long long lint;
typedef pair<ll, ll> p;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ll cst[4][101010];
ll dp[101010][4][4][4];
int track[101010][4][4][4];
int res[101010];
int id[101010];
int rev[101010];

vector<int> g[101010];
int pv;

void dfs(int v){
    id[v] = ++pv; rev[pv] = v;
    for(auto i : g[v]){
        if(!id[i]) dfs(i);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=1; i<=3; i++) for(int j=1; j<=n; j++) cin >> cst[i][j];

    for(int i=1; i<n; i++){
        int s, e; cin >> s >> e;
        g[s].push_back(e);
        g[e].push_back(s);
    }
    int root;
    for(int i=1; i<=n; i++){
        if(g[i].size() == 1) root = i;
        if(g[i].size() > 2){
            cout << -1; return 0;
        }
    }
    dfs(root);

    memset(dp, 0x3f, sizeof dp);
    for(int i=1; i<4; i++) for(int j=1; j<4; j++) for(int k=1; k<4; k++) dp[0][i][j][k] = 0;

    for(int i=1; i<=n; i++){
        for(int a=1; a<=3; a++){
            for(int b=1; b<=3; b++){
                for(int c=1; c<=3; c++){
                    for(int j=1; j<=3; j++){
                        if(a == b || b == c || c == a) continue;
                        if(dp[i][a][b][c] > dp[i-1][j][a][b] + cst[c][rev[i]]){
                            dp[i][a][b][c] = dp[i-1][j][a][b] + cst[c][rev[i]];
                            track[i][a][b][c] = j;
                        }
                    }
                }
            }
        }
    }

    ll ans = 1e18;;
    int a, b, c;
    for(int i=1; i<4; i++) for(int j=1; j<4; j++) for(int k=1; k<4; k++){
        if(ans > dp[n][i][j][k]){
            ans = dp[n][i][j][k];
            a = i, b = j, c = k;
        }
    }

    for(int i=n; i>=1; i--){
        res[rev[i]] = c;
        ll tmp = track[i][a][b][c];
        c = b; b = a; a = tmp;
    }

    cout << ans << "\n";
    for(int i=1; i<=n; i++) cout << res[i] << " ";
}
