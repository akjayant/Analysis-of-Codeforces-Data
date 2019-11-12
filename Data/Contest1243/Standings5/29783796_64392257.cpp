#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e9 + 7;
int kol(int ch) {
	int c = 0;
	while (ch) {
		ch /= 10;
		c++;
	}
	return c;
}
struct dd {
	int a1, a2, a3, a4;
};
signed main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int q;
	cin >> q;
	/*
	while (q--) {
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		vector<int> a(26);
		for (int i = 0; i < n; i++) {    //bca 
			                             //abc
			a[s[i] - 'a']++;
			a[t[i] - 'a']++;
		}
		bool g = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] % 2) {
			
				g = 1;
			}
		} 
		if (g) {
			cout << "No" << endl;
			continue;
		}
		cout << "Yes" << endl;
		vector<pair<int, int> > ans;
		for (int i = 0; i < n-1; i++) {
			if (s[i] == t[i]) continue;
			else {
				bool a = 1;
				for (int j = i; j < n; j++) {
					if (t[j] == s[i]) {
						
						ans.push_back({ i + 1, j });
						ans.push_back({ i + 1, i });
						swap(s[i + 1], t[j]);
						swap(s[i + 1], t[i]);
						a = 0;
						break;
					}
				}
				if (a) {
					for (int j = i + 1; j < n; j++) {
						if (s[i] == s[j]) {
							ans.push_back({ j, i });
							swap(s[j], s[i]);
							break;
						}
					}
				}
			}
		}
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i].first + 1<< " " << ans[i].second + 1 << endl;
		}
	} */
	while (q--) {
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		int ch = 0;
		pair<int, int> p1, p2;
		bool ans = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != t[i]) {
				ch++;
				p2 = p1;
				p1.first = s[i] - 'a';
				p1.second = t[i] - 'a';
			}
			
		}
		if (ch > 2 || ch%2) {
			cout << "No" << endl;
			continue;
		}
		else {
			if (ch == 0) {
				cout << "Yes" << endl;
				continue;
			}
			else if (p1.first == p2.first && p2.second == p1.second) {
				cout << "Yes" << endl;
				continue;
			
			}
			else
				cout << "No" << endl;
			
		
		}
	}
}