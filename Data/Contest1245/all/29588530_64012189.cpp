#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define ll long long int
#define fill(space,a) memset(space,a,sizeof(space))
#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);



int main()
{
	optimize();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int tt; cin >> tt;
	while (tt--) {
		int n, r, p, s;
		string str;
		cin >> n;
		cin >> r >> p >> s;
		cin >> str;
		string ans = "";
		for (int i = 0; i < n; i++) {
			if (str[i] == 'R') {
				if (p > 0) {
					p--;
					ans += "P";
				}
				else {
					ans += "L";
				}
			}
			else if (str[i] == 'P') {
				if (s > 0) {
					s--;
					ans += "S";
				}
				else {
					ans += "L";
				}
			}
			else if(str[i] == 'S') {
				if (r > 0) {
					r--;
					ans += "R";
				}
				else {
					ans += "L";
				}
			}
		}
		int np = 0;
		for (int i = 0; i < n; i++) {
			if (ans[i] != 'L') 
				np++;
		}
		if (np < ((n + 1) / 2)) {
			cout << "NO" << endl;
		}
		else {
			for (int i = 0; i < n; i++) {
				if (ans[i] == 'L') {
					if (r > 0) {
						ans[i] = 'R';
						r--;
					}
					else if (p > 0) {
						ans[i] = 'P';
						p--;
					}
					else if(s > 0) {
						ans[i] = 'S';
						s--;
					}
				}
			}
			cout << "YES" << endl;
			cout << ans << endl;
		}

	}

	return 0;
}