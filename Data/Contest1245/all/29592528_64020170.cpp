#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 2e3 + 5;
const int MOD = 1e9 + 7;
ll x[N], y[N], c[N], k[N];
int p[N];
int sz[N];
int find(int x){
    if(x == p[x])
        return x;
    return(p[x] = find(p[x]));
}
void join(int x, int y){
    x = find(x), y = find(y);
    if(x == y) return;
    if(sz[x] > sz[y]) swap(x, y);
    sz[y] += sz[x];
    p[y] = x;
}
int main(){
    fast;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> k[i];
    }
    for(int i = 1; i <= n + 1; i++){
        p[i] = i, sz[i] = 1;
    }
    // n + 1 is dummy
    vector<pair<ll, pair<int, int> > > edges;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            ll kk = k[i] + k[j];
            ll dist = abs(x[i] - x[j]) + abs(y[i] - y[j]);
            edges.push_back({dist * kk, {i, j}});
        }
        edges.push_back({c[i], {i, n + 1}});
    }
    sort(edges.begin(), edges.end());
    ll cost = 0;
    vector<pair<int, int> > ans;
    vector<int> station;
    for(auto i : edges){
        ll dist = i.first, xx = i.second.first, yy = i.second.second;
        if(find(xx) == find(yy)) continue;
        join(xx, yy);
        cost += dist;
        if(yy == n + 1)
            station.push_back(xx);
        else ans.push_back({xx, yy});
    }
    cout << cost << "\n";
    cout << (int)station.size() << "\n";
    for(auto i : station) cout << i << " ";
    cout << "\n";
    cout << (int)ans.size() << "\n";
    for(auto i : ans)
        cout << i.first << " " << i.second << "\n";
return 0;
}
