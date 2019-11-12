#include <bits/stdc++.h>

using namespace std;


void prepare() {
	
}

void read() {
	
}

void solve() {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
//	cerr << "s = " << s << " t = " << t << endl;
	int pos = -1;
	for (int i = 0; i < n; i++) {
		if (s[i] != t[i]) {
			pos = i;
			break;
		}
	}	
	if (pos == -1) {
		printf("Yes\n");
		return;
	}			
	for (int i = pos + 1; i < n; i++) {
		char s_1 = s[pos];
		char s_2 = s[i];
		char t_1 = t[pos];
		char t_2 = t[i];
//		cerr << " i = " << s_1 << " " << t_1 << " " << s_2 << " " << t_2 << endl;
		if (s_1 == s_2 && t_1 == t_2) {
			swap(s[i], t[pos]);
			break;
		}
	}
	if (s != t) {
		printf("No\n");
	} else {
		printf("Yes\n");
	}
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



