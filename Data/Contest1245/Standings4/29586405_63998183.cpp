#include <bits/stdc++.h>
#define f first
#define s second
#define push push_back
#define pop pop_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#pragma GCC optimize("O3")

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MAXN = 3000, MAXK = 1e6 + 1, INF = 1e9, M = 1e9 + 7;

// mt19937 rnd(0);

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (;n;--n) {
        int a, b;
        cin >> a >> b;
        cout << (__gcd(a,b) == 1? "Finite": "Infinite") << '\n';
    }
	return 0;
}
