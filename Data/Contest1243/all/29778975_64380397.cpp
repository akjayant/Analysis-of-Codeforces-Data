#include <bits/stdc++.h>

using namespace std;

const int M = 1e3 + 3;
int q;

int main () {
	cin >> q;
	while (q--) {
		int n;
		string s, t;
		cin >> n >> s >> t;
		vector <int> v;
		for (int i = 0 ; i < n; i++) {
			if (s[i] != t[i]) {
				v.push_back (i);
			}
		}
		if (v.size() > 2 || v.size() == 1) {puts("NO"); continue;}
		if (v.size() == 0) {puts("YES"); continue;}
		int a = v[0], b = v[1];
		if (s[a] == s[b] && t[a] == t[b]) {puts("YES"); continue;}
		puts("NO");
	}
}