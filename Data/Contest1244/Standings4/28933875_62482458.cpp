#include <bits/stdc++.h>
#define bp __builtin_popcountll
#define pb push_back
#define in(s) freopen(s, "r", stdin);
#define out(s) freopen(s, "w", stdout);
#define inout(s, end1, end2) freopen((string(s) + "." + end1).c_str(), "r", stdin),\
		freopen((string(s) + "." + end2).c_str(), "w", stdout);
#define fi first
#define se second
#define bw(i, r, l) for (int i = r - 1; i >= l; i--)
#define fw(i, l, r) for (int i = l; i < r; i++)
#define fa(i, x) for (auto i: x)
using namespace std;
const int mod = 1e9 + 7, inf = 1061109567;
const long long infll = 4557430888798830399;
const int N = 2e5 + 5;
int n, k, a[N << 1], l[N << 1], r[N << 1];
bool col[N << 1];
int shortest[N << 1];
char conv(int num) {
	if (num) return 'B';
	return 'W';
}
signed main() {
	#ifdef BLU
	in("blu.inp");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	fw (i, 0, n) {
		char c;
		cin >> c;
		if (c == 'B') a[i] = 1;
		else a[i] = 0;
	}
	fw (i, n, 2 * n) a[i] = a[i - n];
	//For each index find distance to the closest non - alternating sequence as x. Then after x steps it
	//becomes this color.
	bool wholeSeq = 1;
	fw (i, 0, n) if (a[i] == a[i + 1]) wholeSeq = 0;
	if (wholeSeq) {
		fw (i, 0, n) cout << conv(a[i] ^ (k & 1));
		return 0;
	}
	int lst = -1;
	fw (i, 0, 2 * n) {
		if (i && a[i] == a[i - 1]) lst = i;
		l[i] = lst;
	}
	lst = -1;
	bw (i, 2 * n, 0) {
		if (i < 2 * n - 1 && a[i] == a[i + 1]) lst = i;
		r[i] = lst;
	}
	fw (i, 0, 2 * n) {
		shortest[i] = inf;
		if (l[i] != -1) {
			shortest[i] = i - l[i];
			col[i] = a[l[i]];
		}
		if (r[i] != -1 && r[i] - i < shortest[i]) {
			shortest[i] = r[i] - i;
			col[i] = a[r[i]];
		}
//		cout << "col[" << i << "] = " << col[i] << "\n";
	}
	fw (i, 0, n) {
		if (shortest[i] > shortest[i + n]) {
			swap(shortest[i], shortest[i + n]);
			swap(col[i], col[i + n]);
		}
	}
	fw (i, 0, n) {
		int finalCol;
		if (k >= shortest[i]) finalCol = col[i];
		else finalCol = (a[i] ^ (k & 1));
		cout << conv(finalCol);
	}
	return 0;
}