#include <bits/stdc++.h>
#define FOR(i, u, v) for (int i = u; i <= v; i++)
#define FORD(i, v, u) for (int i = v; i >= u; i--)
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define mod 1000000007

using namespace std;

int n;
string s, t;
vector<int> all;

void solve() {
    all.clear();
    FOR(i, 1, n) {
        if (s[i] != t[i]) all.PB(i);
    }
    if (all.size() >= 3 || all.size() == 1) {
        cout <<"No"<<'\n';
        return;
    }
    int u = all[0], v = all[1];
    if (s[u] != s[v] || t[u] != t[v]) {
        cout <<"No";
    }
    else cout <<"Yes";
    cout <<endl;
    return;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen("INP.TXT", "r")) {
		freopen("INP.TXT", "r", stdin);
    }
    int Tests; cin >> Tests;
    while (Tests--) {
        cin >> n >> s >> t;
        s = " " + s;
        t = " " + t;
        solve();
    }
}

