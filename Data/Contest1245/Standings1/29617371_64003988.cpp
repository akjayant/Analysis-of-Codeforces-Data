#include <bits/stdc++.h>

using namespace std;



void prepare() {
	
}

void read() {
	
}

pair<bool, string> play(int r, int p, int s, string str) {
	pair<bool, string> result;
	result.first = false;
	result.second = string(str.size(), '-');

	int need = (str.size() + 1) / 2;
	for (int i = 0; i < (int) str.size(); i++) {
		if (str[i] == 'R' && p > 0) {
			p--;
			need--;
			result.second[i] = 'P';
		}
		if (str[i] == 'P' && s > 0) {
			s--;
			need--;
			result.second[i] = 'S';
		}
		if (str[i] == 'S' && r > 0) {
			r--;
			need--;
			result.second[i] = 'R';
		}
	}	
	if (need > 0) {		
		return result;
	}
//	fprintf(stderr, "%d %d %d\n", r, p, s);

	for (int i = 0; i < (int) str.size(); i++) {
		if (result.second[i] != '-') continue;
		if (p > 0) {
			p--;			
			result.second[i] = 'P';
			continue;
		}
		if (s > 0) {
			s--;			
			result.second[i] = 'S';
			continue;
		}
		if (r > 0) {
			r--;			
			result.second[i] = 'R';
			continue;
		}
	}	
	result.first = true;
	return result;
}

void solve() {
	int test;
	scanf("%d", &test);
	for (int t = 0; t < test; t++) {
		int n;
		scanf("%d", &n);
		int r, p, s;
		scanf("%d %d %d", &r, &p, &s);
		char str[123];
		scanf("%s", str);
		pair<bool, string> result = play(r, p, s, string(str));
		if (result.first) {
			printf("YES\n%s\n", result.second.c_str());
		} else {
			printf("NO\n");
		}
	}
}

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	prepare();
	read();
	solve();
	
	return 0;
}



