#include <bits/stdc++.h>
#define mp make_pair
#define debug(x) cout << #x << ": " << x << endl
#define pb push_back
typedef long long LL;
const int maxn = 3e5 + 10;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3f;
using namespace std;
int n, t;
string s, r;
typedef pair<int, int> pii;
vector<int> dif;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> s >> r;
		dif.clear();
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] != r[i])
				dif.pb(i);
		}
		if (dif.size() > 2||dif.size()==1) {
			cout << "NO\n";
		}
		else {
			if (dif.size() == 0)
				cout << "YES\n";
			else {
				if (s[dif[0]] == s[dif[1]] && r[dif[1]] == r[dif[0]])
					cout << "YES\n";
				else
					cout << "NO\n";
			}
		}
	}
}