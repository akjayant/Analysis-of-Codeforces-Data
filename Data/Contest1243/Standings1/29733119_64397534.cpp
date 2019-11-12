/* Apaar */

/* Apaar */

/* Apaar */

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
		string s, t;
		cin >> s >> t;
		int num[26] = {};
		for (i = 0; i < n; i++) {
			num[s[i] - 'a']++;
			num[t[i] - 'a']++;
		}
		for (i = 0; i < 26; i++) {
			if (num[i] & 1) {
				sum = 1;
				break;
			}
		}
		if (sum == 1) {
			cout << "No\n";
		}
		else {
			vector<int> pos;
			vector<P> res;
			sum = 0;
			for (i = 0; i < n; i++) {
				if (s[i] != t[i]) {
					bool done = 0;
					for (j = i + 1; j < n; j++) {
						if (s[i] == s[j]) {
							res.pb({j, i});
							swap(s[j], t[i]);
							done = 1;
							break;
						}
					}
					if (!done) {
						for (j = i + 1; j < n; j++) {
							if (t[j] == s[i]) {
								res.pb({i + 1, j});
								swap(s[i + 1], t[j]);
								res.pb({i + 1, i});
								swap(s[i + 1], t[i]);
								done = 1;
								break;
							}
						}
					}
					if (!done) {
						cout << "No\n";
						sum = 1;
						break;
					}
				}
			}
			if (sum == 1) {
				cout << "No\n";
				continue;
			}
			cout << "Yes\n";
			cout << res.size() << '\n';
			for (auto x : res) {
				cout << x.F + 1 << " " << x.S + 1 << '\n';
			}
		}
	}
}