#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define all(x) (x).begin(), (x).end()
#define forn(i, n) for(int i = 0; i < n; ++i)
#define fore(i, a, b) for(int i = a; i < b; ++i)

#define endl '\n'

const int MOD = 1000000007;
const int MOD2 = 998244353;

vector<int> p, sz;

int find(int a) {
    if (p[a] == a) {
        return a;
    }
    return p[a] = find(p[a]);
}

bool uni(int a, int b) {
    a = find(a);
    b = find(b);
    if (sz[a] < sz[b]) {
        swap(a, b);
    }
    if (a != b) {
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
    	cin >> x[i] >> y[i];
	}
    p.resize(n + 1);
    sz.resize(n + 1);
    for (int i = 0; i <= n; ++i) {
        p[i] = i;
        sz[i] = 1;
    }
    vector<tuple<ll, int, int>> ar;
    ar.reserve(4000000);
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        ar.emplace_back(v, 0, i + 1);
    }
    vector<ll> mult(n);
    for (int i = 0; i < n; ++i) {
    	cin >> mult[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			ll dst = abs(x[i] - x[j]) + abs(y[i] - y[j]);
			ar.emplace_back(dst * (mult[i] + mult[j]), i + 1, j + 1);
		}
	}
    sort(all(ar));
    ll ans = 0;
    vector<int> built;
    vector<pair<int, int>> connect;
    for (auto& t: ar) {
    	int a = get<1>(t);
    	int b = get<2>(t);
        if (uni(a, b)) {
            ans += get<0>(t);
            if (a == 0) {
            	built.push_back(b);
			} else {
				connect.emplace_back(a, b);
			}
        }
    }
    cout << ans << endl;
    cout << built.size() << endl;
    for (int v: built) {
    	cout << v << " ";
	}
	cout << endl;
	cout << connect.size() << endl;
	for (auto& p: connect) {
		cout << p.first << " " << p.second << endl;
	}
}