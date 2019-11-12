#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
typedef long long lint;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
typedef unsigned long long ulint;
#define endl '\n'
#define fst first
#define sed second
#define pb push_back
#define mp make_pair
#define rint register int
#define SZ(x) (int((x).size()))
#define all(x) (x).begin(), (x).end()
#define reveal(x) cerr << #x << " = " << (x) << endl
#define rep(it, f, e) for (rint it = (f); it <= (e); ++it)
#define per(it, f, e) for (rint it = (f); it >= (e); --it)
#define repe(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)
int a[310][310];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	int tot = 0;
	rep (i, 1, n) {
		if (i & 1) rep (j, 1, n) {
			a[j][i] = ++tot;
		} else per (j, n, 1) {
			a[j][i] = ++tot;
		}
	}
	rep (i, 1, n){
		rep (j, 1, n - 1) {
			cout << a[i][j] << ' ';
		}	cout << a[i][n] << endl;
	}
	return 0;
}