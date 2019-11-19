#include<bits/stdc++.h>
#define fi first
#define se second
#define all(x) x.begin() , x.end()
#define rall(x) x.rbegin() , x.rend()
#define pb push_back
typedef long long ll;
typedef long double ld;
using namespace std;
const int N = 1e5 + 1;
const ll INF = 1e18;
ll dp[N][3][3];
vector < vector < int > > cost ,g;
vector < int > curr;
bool cant = 1;
int ANC;
void dfs(int v, int p){
    curr.pb(v);
    for(auto &i : g[v]){
        if(i == p)continue;
        dfs(i , v);
    }
}
void preproc(){
    for(auto &i : dp)
        for(auto &j : i)for(auto &z : j)z = INF;

}

signed main() {
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int n;
    cin >> n;
    g.resize(n);
    preproc();
    cost.resize(n , vector < int > (3));
    for(int z = 0 ; z < 3; ++z){
        for(int j = 0 ; j < n; ++j){
            cin >> cost[j][z];
        }
    }
    for(int z = 0 ; z < n - 1 ; ++z){
        int a , b;
        cin >> a >> b;
        --a , --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    for(int z = 0 ; z < n; ++z){
        if(g[z].size() >= 3)return cout << -1 ,0;
    }

    for(int z = 0; z < n; ++z){
        if(g[z].size() == 1){
            dfs(z, -1);
            break;
        }
    }
    for(int z= 0 ; z < 3; ++z){
        for(int j = 0 ; j < 3; ++j){
            dp[1][z][j] = cost[curr[0]][z] + cost[curr[1]][j];
        }
    }
    for(int j = 2 ; j < n;  ++j){
        for(int prev = 0 ; prev < 3; ++prev){
            for(int p = 0 ; p < 3; ++p){
                if(p == prev)continue;
                if(dp[j][p][3 - prev - p] > dp[j - 1][prev][p] + cost[curr[j]][3 - prev - p]){
                    dp[j][p][3 - prev - p] = dp[j - 1][prev][p] + cost[curr[j]][3 - prev - p];
                }
            }
        }
    }
    ll ans = INF;
    vector < int > answer(n);
    int F , S;
    for(int z = 0 ; z < 3; ++z){
        for(int j = 0 ; j < 3; ++j){
            if(dp[n - 1][z][j] < ans)
            ans = dp[n - 1][z][j] , F = z , S = j;
        }
    }
    cout << ans <<'\n';
    int current = n - 1;
    while(current >= 2){
        answer[curr[current]] = S;
        int prev = 3 - F - S;
        S = F , F = prev;
        --current;
    }
    answer[curr[0]] = F;
    answer[curr[1]] = S;
    for(auto &i : answer)cout << i + 1 << ' ';
    return 0;
}
