#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
const ll inf = 1e18;
const int N = 2 * 1e5 + 10;
 
ll a[N], b[N], c[N]; 

vector<ll> v[N];

ll Get(ll px, ll py, ll node, ll par){
    for(auto i: v[node]){
        if(par == i)    continue;
        if(px != 3 and py != 3) return c[node] + Get(py, 3, i, node);
        if(px != 2 and py != 2) return b[node] + Get(py, 2, i, node);
        return a[node] + Get(py, 1, i, node);
    }
    if(px != 3 and py != 3) return c[node];
    if(px != 2 and py != 2) return b[node];
    return a[node];
}

void Solve(ll px, ll py, ll node, ll par){
    if(px != 3 and py != 3) a[node] = 3;
    if(px != 2 and py != 2) a[node] = 2;
    if(px != 1 and py != 1) a[node] = 1;
    for(auto i: v[node]){
        if(par != i)    Solve(py, a[node], i, node);    
    }
}

int main(){
    //ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    ll n, st, x, y;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for(int i = 1; i <= n; ++i){
        cin >> b[i];
    }
    for(int i = 1; i <= n; ++i){
        cin >> c[i];
    }
    for(int i = 0; i < n - 1; ++i){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i = 1; i <= n; ++i){
        if(v[i].size() > 2) return cout << "-1",  0;
        if(v[i].size() == 1)    st = i;
    }
    ll mx = inf, sx, sy;
    for(int i = 1; i <= 3; ++i){
        for(int j = 1; j <= 3; ++j){
            if(i == j)  continue;
            ll val = Get(i, j, st, -1);
            if(val < mx){
                mx = val;
                sx = i;
                sy = j;
            }
        }
    }
    cout << Get(sx, sy, st, -1) << "\n";
    Solve(sx, sy, st, -1);
    for(int i = 1; i <= n; ++i){
        cout << a[i] << " ";
    }
}