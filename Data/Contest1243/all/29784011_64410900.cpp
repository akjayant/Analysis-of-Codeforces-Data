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
int n, cnt[26];
string s, t;
void proc() {
	cin >> n >> s >> t;
	memset(cnt, 0, sizeof cnt);
	int cntNotMatch = 0, not1 = -1, not2 = -1;
	fw (i, 0, n) {
		cnt[s[i] - 'a']++;
		if (s[i] != t[i]) {
			cntNotMatch++;
			if (not1 == -1) not1 = i;
			else if (not2 == -1) not2 = i;
		}
	}
	if (cntNotMatch == 0) {
		fw (i, 0, 26) if (cnt[i]) {
			cout << "Yes\n";
			return;
		}
	}
	if (cntNotMatch == 2) {
		swap(s[not1], t[not2]);
		bool bad = 0;
		fw (i, 0, n) {
			if (s[i] != t[i]) bad = 1;
		}
		if (bad) cout << "No\n";
		else cout << "Yes\n";
		return;
	}
	cout << "No\n";
}
signed main() {
	#ifdef BLU
	in("blu.inp");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) proc();
	return 0;
}