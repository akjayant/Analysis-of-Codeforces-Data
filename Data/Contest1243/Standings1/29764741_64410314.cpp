#include <bits/stdc++.h>
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1 << 30;
const ll LINF = 1LL << 62;

vector <int> g[MAX];
set <int> s;
int ans;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }
    for(int i = 1; i <= n; i++) {
        s.insert(i);
        sort(all(g[i]));
    }
    ans = n - 1;
    for(int i = 1; i <= n; i++) {
        if(s.find(i) != s.end()) {
            s.erase(i);
            queue <int> q;
            q.push(i);
            while(!q.empty()) {
                int x = q.front();
                q.pop();
                int idx = 0;
                vector <int> ers;
                for(auto it = s.begin(); it != s.end(); it++) {
                    while(idx + 1 < g[x].size() && g[x][idx+1] <= *it) idx++;
                    if(g[x].empty()) {
                        q.push(*it);
                        ans--;
                        ers.eb(*it);
                    }
                    else if(g[x][idx] != *it) {
                        q.push(*it);
                        ans--;
                        ers.eb(*it);
                    }
                }
                for(auto j : ers) {
                    s.erase(j);
                }
            }
        }
    }
    cout << ans;
}