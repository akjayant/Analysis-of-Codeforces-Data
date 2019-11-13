#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string sw("RPS"), sl("SRP");
    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	int rps[3];
    	cin >> rps[0] >> rps[1] >> rps[2];
    	string s;
    	cin >> s;
    	int win = 0;
    	string ans;
    	ans.resize(n);
    	for (int i = 0; i < n; ++i) {
    	    for (int j = 0; j < 3; ++j) {
    	    	if (sl[j] == s[i] && rps[j]) {
    	    	    ++win;
    	    	    ans[i] = sw[j];
    	    	    --rps[j];
    	    	    break;
		}
	    }
	}
	for (int i = 0; i < n; ++i) {
	    if (ans[i] == '\0') {
		for (int j = 0; j < 3; ++j) {
		    if (rps[j]) {
		    	ans[i] = sw[j];
			--rps[j];
			break;
		    }
		}
	    }
	}
	if (win >= n / 2 + (n % 2 == 0 ? 0 : 1)) {
	    cout << "YES\n" << ans << '\n';
	} else {
	    cout << "NO\n";
	}
    }
}
