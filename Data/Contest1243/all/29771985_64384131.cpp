#include <bits/stdc++.h>

using namespace std;



void prepare() {
	
}

void read() {
	
}

void solve() {
	int n;
	string s, t;
	cin >> n >> s >> t;
	vector<int> cnt(26, 0);
	for (int i = 0; i < (int) s.size(); i++) {
		cnt[s[i] - 'a']++;
		cnt[t[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (cnt[i] % 2 != 0) {
			printf("No\n");
			return;
		}
	}
	printf("Yes\n");	
	vector<pair<int, int>> answer;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == t[i]) continue;
		int pos = -1;
		for (int j = i + 1; j < n; j++) {
			if (t[i] == t[j]) {
				pos = j;
				break;
			}
		}
		if (pos != -1) {
			answer.push_back(make_pair(i, pos));
			swap(s[i], t[pos]);
			continue;
		} 
		for (int j = i + 1; j < n; j++) {
			if (t[i] == s[j]) {
				pos = j;
				break;
			}
		}
		assert(pos != -1);
		answer.push_back(make_pair(pos, i + 1));
		swap(s[pos], t[i + 1]);
		answer.push_back(make_pair(i, i + 1));
		swap(s[i], t[i + 1]);
	}
	printf("%d\n", (int) answer.size());
	for (pair<int, int> s : answer) {
		printf("%d %d\n", s.first + 1, s.second + 1);
	}
	//cerr << s << " " << t << endl;
}

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	prepare();
	read();
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {		
		solve();
	}
	
	return 0;
}



