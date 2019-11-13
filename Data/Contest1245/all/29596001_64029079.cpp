#include <bits/stdc++.h>
#include <stdio.h>
 
using namespace std;
 
#define int long long
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)

void solve();

signed main () {
    cout.precision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    int t = 1; 
    cin >> t;
    int tt = t;
    while (t--) { 
        solve();
    }
    return 0;
}
int cnt[3] = {0};
string lol = "PSR";
int n;
int us[500];
void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		us[i] = -1;
    memset(cnt, 0, sizeof cnt);
    cin >> cnt[2] >> cnt[0] >> cnt[1];
    assert(cnt[0] + cnt[1] + cnt[2] == n);
   	vector<int> them;
   	for (int i = 0; i < n; i++) {
   		char c;
   		cin >> c;
   		for (int j = 0; j < 3; ++j) {
   			if (lol[j] == c)
   				them.push_back(j);
   		}
   	}
   	int win = 0;
   	for (int i = 0; i < n; i++) {
   		int best = them[i] + 1;
   		best %= 3;
   		if (cnt[best]) {
   			++win;
   			us[i] = best;
   			--cnt[best];
   			continue;
   		}
   	}
   	for (int i = 0; i < n; ++i) {
   		if (us[i] != -1)
   			continue;
   		for (int j = 0; j < 3; ++j) {
   			if (cnt[j]) {
   				us[i] = j;
   				--cnt[j];
   				break;
   			}
   		}
   	}
   	if (win >= (n + 1) / 2) {
   		cout << "YES\n";
   		for (int j = 0; j < n; ++j) {
   			cout << lol[us[j]];
   		}
   		cout << '\n';
   	}
   	else {
   		cout << "NO\n";
   	}
}       
