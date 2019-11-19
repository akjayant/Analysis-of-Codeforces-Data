/** Simplicity is the final achievement **/

#include <bits/stdc++.h>

using namespace std;

const int N = 2e3+55;
const long long MD = 1e9+7;

long long n, m;
string s;

long long arr[N];

long long c[N], k[N];
pair<int, int> inp[N];

typedef pair<pair<long long, long long>, pair<long long, long long>> PLL;

priority_queue<PLL, vector<PLL>, greater<PLL>> pq;

int mark[N], par[N];

int f(int u) {
    return par[u] == u ? u : par[u] = f(par[u]);
}


void un(int u, int v) {
    int pu = f(u), pv = f(v);
    if (pu != pv) {
        mark[pv] |= mark[pu];
        par[pu] = pv;
    }
}


int32_t main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    /** ONLY FOOLS RUSH IN **/

    cin >> n;

    for (int i = 0; i < n; i++) cin >> inp[i].first >> inp[i].second;
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n; i++) cin >> k[i];
    for (int i = 0; i < n; i++) par[i] = i;


    for (int i = 0; i < n; i++) {
        pq.push({{c[i], 0}, {i, 0}});
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            pq.push({{(k[i]+k[j])*(0ll + abs(inp[i].first - inp[j].first) + abs(inp[i].second - inp[j].second)), 1}, {i, j}});
        }
    }

    long long ans = 0;
    vector<int> C;
    vector<pair<int, int>> P;

    while (!pq.empty()) {
        auto x = pq.top();
        pq.pop();
        if (x.first.second == 0) {
            if (!mark[f(x.second.first)]) {
                ans += x.first.first;
                C.push_back(x.second.first);
                mark[f(x.second.first)] = 1;
            }
        } else {
            int pi = f(x.second.first), pj = f(x.second.second);
            if (pi != pj && (!mark[pi] || !mark[pj])) {
                un(pi, pj);
                P.push_back(x.second);
                ans += x.first.first;
            }
        }
    }

    cout << ans << endl << C.size() << endl;
    for (auto x : C) cout << x+1 << " ";
    cout << endl << P.size() << endl;
    for (auto x : P) cout << x.first+1 << " " << x.second+1 << "\n";
    return 0;
}
