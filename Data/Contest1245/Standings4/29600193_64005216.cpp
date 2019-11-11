#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define esp 1e-6

typedef long long ll;
using namespace std;

ll pow_m (ll a,ll b,ll mod) {
	ll res = 1;
	a = a % mod;
	while (b) {
		if(b & 1)	res = (res * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return res;
}


string ans;
int n, r, p, s, cnt = 0;
int main() {
	int t;
	cin >> t;
	while (t--) {
		ans.clear();
		cnt = 0;
		cin >> n >> r >> p >> s;
		string str;
		cin >> str;
		int firtotryR = 0, firtotryP = 0, firtotryS = 0;
		for (int i = 0; i < n; i++) {
			if (str[i] == 'R')	firtotryP++;
			else if (str[i] == 'S')	firtotryR++;
			else	firtotryS++;
		}
		for (int i = 0; i < n; i++) {
			if (str[i] == 'R') {
				if (p) {
					p--;
					cnt++;
					ans.push_back('P');
				} else {
					int flowR = r - firtotryR, flowS = s - firtotryS;
					if (r && flowR >= flowS) {
						r--;
						ans.push_back('R');
					} else {
						s--;
						ans.push_back('S');
					}
				}
				firtotryP--;
				firtotryP = max(firtotryP, 0);
			} else if(str[i] == 'S') {
				if (r) {
					r--;
					cnt++;
					ans.push_back('R');
				} else {
					int flowP = p - firtotryP, flowS = s - firtotryS;
					if (p && flowP >= flowS) {
						p--;
						ans.push_back('P');
					} else {
						s--;
						ans.push_back('S');
					}
				}
				firtotryR--;
				firtotryR = max(firtotryR, 0);
			} else {
				if (s) {
					s--;
					cnt++;
					ans.push_back('S');
				} else {
					int flowP = p - firtotryP, flowR = r - firtotryR;
					if (r && flowR >= flowP) {
						r--;
						ans.push_back('R');
					} else {
						p--;
						ans.push_back('P');
					}
				}
				firtotryS--;
				firtotryS = max(firtotryS, 0);
			}
		}
		long long fir = ((n + 1) / 2);
		if (cnt >= fir) {
			puts("YES");
			cout << ans << endl;

		} else {
			puts("NO");

		}
	}
	return 0;
}