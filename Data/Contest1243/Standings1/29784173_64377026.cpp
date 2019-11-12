#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define mp make_pair
#define ll long long
using namespace std;
ll n, t, k, m, ans = 0;
ll a[300010];
string s1, s2;
int main() {
	ios::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> s1 >> s2;
		vector<int> vec;
		for (int i = 0; i < n; ++i) {
			if (s1[i] != s2[i]) vec.push_back(i);
		}
		if (vec.size() != 2) {
			cout << "No\n";
			continue;
		}
		if (s1[vec[0]] == s1[vec[1]] && s2[vec[1]] == s2[vec[0]]) {
			cout << "Yes\n";
			continue;
		}
		else {
			cout << "No\n";
			continue;
		}
	}
}
