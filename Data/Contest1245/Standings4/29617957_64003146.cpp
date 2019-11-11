#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string ans;

int main() {
	int t;
	cin >> t;
	while (t--) {
		ans.clear();
		int n, r, p, s, cnt = 0;
		cin >> n >> r >> p >> s;
		string str;
		cin >> str;
		int needR = 0, needP = 0, needS = 0;
		for (int i = 0; i < n; i++) {
			if (str[i] == 'R') {
				needP++;
			}
			else if (str[i] == 'S') {
				needR++;
			}
			else {
				needS++;
			}
		}
		for (int i = 0; i < n; i++) {
			if (str[i] == 'R') {
				if (p) {
					p--;
					cnt++;
					ans.push_back('P');
				}
				else {
					int flowR = r - needR, flowS = s - needS;
					if (r && flowR >= flowS) {
						r--;
						ans.push_back('R');
					}
					else {
						s--;
						ans.push_back('S');
					}
				}
				needP--;
				needP = max(needP, 0);
			}
			else if(str[i] == 'S') {
				if (r) {
					r--;
					cnt++;
					ans.push_back('R');
				}
				else {
					int flowP = p - needP, flowS = s - needS;
					if (p && flowP >= flowS) {
						p--;
						ans.push_back('P');
					}
					else {
						s--;
						ans.push_back('S');
					}
				}
				needR--;
				needR = max(needR, 0);
			}
			else {
				if (s) {
					s--;
					cnt++;
					ans.push_back('S');
				}
				else {
					int flowP = p - needP, flowR = r - needR;
					if (r && flowR >= flowP) {
						r--;
						ans.push_back('R');
					}
					else {
						p--;
						ans.push_back('P');
					}
				}
				needS--;
				needS = max(needS, 0);
			}
		}
		if (cnt >= ((n + 1) / 2)) {
			cout << "YES" << endl << ans << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
