#include<bits/stdc++.h>

using namespace std;
using ll = int64_t;

#define fo(i,a,z) for(ll i=(a);i<(z);++i)
#define MAX 100005

ll n, ans, connected = 0;
pair<ll,ll> co[MAX];
ll pcost[MAX];
ll wcost[MAX];
ll seen[MAX];
set<pair<ll,ll>> edges;
set<ll> powers;

int main() {
    cin >> n;
    priority_queue<tuple<ll,ll,ll>, vector<tuple<ll,ll,ll>>, std::greater<tuple<ll,ll,ll>>> pq; // edge_cost, city_n, source
    fo(i,0,n) cin >> co[i].first >> co[i].second;
    fo(i,0,n) cin >> pcost[i];
    fo(i,0,n) cin >> wcost[i];
    fo(i,0,n) pq.emplace(pcost[i], i, -1);
    while (connected < n) {
        auto [ec, ci, si] = pq.top(); pq.pop();
        if (seen[ci]) continue;
        //cout << ec << ' ' << ci << ' ' << si << '\n';
        ++connected;
        seen[ci] = 1;
        ans += ec;
        if (si == -1) {
            powers.emplace(ci+1);
        } else {
            edges.emplace(si+1,ci+1);
        }
        fo(i,0,n) if(!seen[i]) {
            ll wwcost = wcost[ci] + wcost[i];
            ll dist = abs(co[i].first - co[ci].first) + abs(co[i].second - co[ci].second);
            pq.emplace(wwcost*dist, i, ci);
        }
    }
    //cout << '\n';
    cout << ans << '\n';
    cout << powers.size() << '\n';
    for(auto v: powers) cout << v << ' ';
    cout << '\n';
    cout << edges.size() << '\n';
    for(auto [a, b]: edges) cout << a << ' ' << b << '\n';
    return 0;
}
