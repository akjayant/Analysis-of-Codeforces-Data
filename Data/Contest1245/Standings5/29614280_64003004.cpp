#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<functional>
#include<iomanip>
#include<cstdio>
#include<climits>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cassert>
using namespace std;

typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
constexpr int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 10;


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int r, p, s;
		cin >> r >> p >> s;
		string str;
		vector<char>ans;
		cin >> str;
		ans.resize(str.size());
		int cnt = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'R' && p) {
				ans[i] = 'P';
				cnt++;
				p--;
			}
			else if (str[i] == 'P' && s) {
				ans[i] = 'S';
				cnt++;
				s--;
			}
			else if (str[i] == 'S' && r) {
				ans[i] = 'R';
				cnt++;
				r--;
			}
		}
		for (int i = 0; i < str.size(); i++) {
			if (ans[i] == 0) {
				if (r) {
					ans[i] = 'R';
					r--;
				}
				else if (p) {
					ans[i] = 'P';
					p--;
				}
				else {
					ans[i] = 'S';
					s--;
				}
			}
		}
		if (cnt >= (n + 1) / 2) {
			cout << "YES\n";
			for (auto c : ans) cout << c;
			cout << "\n";
		}
		else cout << "NO\n";
	}

	return 0;
}