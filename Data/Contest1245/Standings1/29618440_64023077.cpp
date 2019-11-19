#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

const int N = 2001;

int n, dsu[N];
ll con[N];
vector <pair <int, int> > a;
vector <int> c, k;
vector <pair <int, int> > connections;

int dist(int i, int j){
    return abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second);
}
int find(int x){
    if(dsu[x] == x) return x;
    return dsu[x] = find(dsu[x]);
}
int merge(int x, int y, ll cost){
    x = find(x);
    y = find(y);
    if(x == y) return 0;
    if(con[x] + con[y] + c[x] + c[y] < con[x] + con[y] + cost + min(c[x], c[y])) return 0;
    if(c[y] < c[x]) swap(x, y);
    con[x] += con[y];
    con[x] += cost;
    dsu[y] = x;
    return 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        dsu[i] = i;
    }
    a.resize(n);
    for(auto &i : a) cin >> i.first >> i.second;
    c.resize(n);
    for(auto &i : c) cin >> i;
    k.resize(n);
    for(auto &i : k) cin >> i;
    vector <pair <ll, pair <int, int> > > all;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i == j) continue;
            all.push_back(make_pair(1LL * dist(i, j) * (k[i] + k[j]), make_pair(i, j)));
        }
    }
    sort(all.begin(), all.end());
    for(auto &i : all){
        if(merge(i.second.first, i.second.second, i.first)){
            connections.push_back(i.second);
        }
    }
    ll ans = 0;
    vector <int> stations;
    for(int i = 0 ; i < n ; i++){
        if(dsu[i] != i) continue;
        ans += con[i] + c[i];
        stations.push_back(i);
    }
    cout << ans << endl;
    cout << stations.size() << endl;
    for(auto &i : stations) cout << i + 1 << " ";
    cout << endl;
    cout << connections.size() << endl;
    for(auto &i : connections){
        cout << i.first + 1 << " " << i.second + 1 << endl;
    }
}
