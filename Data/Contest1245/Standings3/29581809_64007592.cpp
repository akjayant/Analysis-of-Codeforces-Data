// Author : Apaar
// Built  : 01-11-2019 20:33:45

#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t; while (t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n;
		int r, p, c;
		cin >> r >> p >> c;
		string s;
		cin >> s;
		vector<char> res(n, '?');
		for (i = 0; i < n; i++) {
			if (p > 0 && s[i] == 'R') {
				ans++; p--;
				res[i] = 'P';
			}
			if (s[i] == 'P' && c > 0) {
				ans++; c--;
				res[i] = 'S';
			}
			if (s[i] == 'S' && r > 0) {
				ans++; r--;
				res[i] = 'R';
			}
		}
		if (ans  < (n + 1) / 2) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
			for (i = 0; i < n; i++) {
				if (res[i] == '?') {
					if (p > 0) {
						p--;
						cout << "P";
					}
					else if (c > 0) {
						c--;
						cout << "S";
					}
					else {
						r--;
						cout << "R";
					}
				}
				else {
					cout << res[i];
				}
			}
			cout << '\n';
		}
	}
}