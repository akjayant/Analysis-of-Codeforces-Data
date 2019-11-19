#define IOS ios::sync_with_stdio(false);
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 7;
const int M = 3e5 + 7;
const int INF = 1e8 + 7;
ll mod = 1e9 + 7;

int n, x[2222], y[2222], k[2222], vis[2222], type[2222];
ll c[2222];
int main(){
    IOS;
    cin >> n;
    ll ans = 0;
    for(int i = 1; i <= n; ++ i) type[i] = 0;
    for(int i = 1; i <= n; ++ i) cin >> x[i] >> y[i];
    for(int i = 1; i <= n; ++ i) cin >> c[i];
    for(int i = 1; i <= n; ++ i) cin >> k[i];

    vector<int> dots;
    vector<pair<int, int>> edges;

    for(int i = 1; i <= n; ++ i){

        int min_cost_id = -1;
        for(int j = 1; j <= n; ++ j){
            if(vis[j]) continue;
            if(min_cost_id == -1 || c[min_cost_id] > c[j]){
                min_cost_id = j;
            }
        }
        if(type[min_cost_id] == 0) dots.push_back(min_cost_id);
        else edges.push_back(make_pair(min_cost_id, type[min_cost_id]));

        ans += c[min_cost_id];
        vis[min_cost_id] = 1;
        for(int j = 1; j <= n; ++ j){
            if(vis[j]) continue;
            ll new_cost = 1ll * (abs(x[j]-x[min_cost_id]) + abs(y[j]-y[min_cost_id])) * (k[min_cost_id] + k[j]);
            //cout << min_cost_id << " " << j << " " << new_cost << endl;
            if(new_cost < c[j]){
                c[j] = new_cost;
                type[j] = min_cost_id;
            }
        }
    }
    cout << ans << endl;
    cout << dots.size() << endl;
    for(int i = 0; i < dots.size(); ++ i) {
        cout << dots[i] << (i == dots.size() - 1 ? '\n' : ' ');
    }
    cout << edges.size() << endl;
    for(int i = 0; i < edges.size(); ++ i){
        cout << edges[i].first << " " << edges[i].second << endl;
    }

    return 0;
}