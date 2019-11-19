#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define x first
#define y second
#define pll pair<ll, ll>
#define pii pair<int, int>
#define mll map<ll, ll>
#define mii map<in, int>
#define vll vector<ll>
#define vi vector<int>
#define pb push_back
#define p push
using namespace std;

ll si[4000], p[4000], v[4000], c[4000], n, k[4000], ans, cnt = 0, what[4000];
pair<ll, pll> ed[5005000];
pll a[4000];
vector<pair<ll, pll>> tree;
set<int> s;
set<pii> s2;
void init() {
    for(int i = 1;i<=n;i++) {
        p[i] = i;
        si[i] = 1;
        v[i] = c[i];
        ans += c[i];
        s.insert(i);
        what[i] = i;
    }
    
}

int get(int i) {
    if(i == p[i]) return i;
    return p[i] = get(p[i]);
}

void comp(int u, int V, ll w) {
    if(si[u] < si[V]) swap(u, V);
    if(v[V] >= v[u]) {
        s.erase(what[V]);
        what[u] = what[u];
    } else {
        s.erase(what[u]);
        what[u] = what[V];
    }
    ans -= max(v[V], v[u]);
    ans += w;
    v[u] = min(v[V], v[u]);
    p[V] = u;
    si[u] += si[V];
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i = 1;i<=n;i++) {
        cin>>a[i].x>>a[i].y;
    }
    for(int i = 1;i<=n;i++) cin>>c[i];
    for(int i = 1;i<=n;i++) cin>>k[i];
    for(int i = 1;i<=n;i++) {
        ans += c[i];
        for(int j = 1;j<=n;j++) {
            if(i != j) {
                ed[cnt] = {(k[i] + k[j])*(abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y)), {i, j}};
                cnt++;
            }
        }
    }
    sort(ed, ed+cnt);
    init();
    for(int i = 0;i<cnt;i++) {
        int u = get(ed[i].y.x);
        int V = get(ed[i].y.y);
        if(u != V) {
            comp(u, V, 0);
            tree.pb(ed[i]);
        }
    }
    ans = 0;
    init();
    for(auto x: tree) {
        int u = get(x.y.x);
        int V = get(x.y.y);
        if(u != V) {
            if(x.x <= v[u] || x.x <= v[V]) {
                comp(u, V, x.x);
                s2.insert({x.y.x, x.y.y});
            }
        }
    }
    cout<<ans<<'\n'<<s.size()<<'\n';
    for(auto x:s) cout<<x<<' ';
    cout<<'\n'<<n - s.size()<<'\n';
    for(auto x:s2) cout<<x.x<<' '<<x.y<<'\n';
}
//