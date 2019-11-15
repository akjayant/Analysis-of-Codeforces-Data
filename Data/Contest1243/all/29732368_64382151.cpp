#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define E "\n"

using namespace std;
const long long MOD = (long long)1e9 + 7;

int t, n;
string s1, s2;
vector<int> vec;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> s1 >> s2;
		vec.clear();
		for (int i = 0; i < n; i++) {
			if (s1[i] != s2[i]) {
				vec.pb(i);
			}
		}
		if (vec.size() == 2) {
			if (s1[vec[0]] == s1[vec[1]] && s2[vec[0]] == s2[vec[1]]) {
				cout << "YES" << E;
			}
			else {
				cout << "NO" << E;
			}
		}
		else {
			cout << "NO" << E;
		}
	}
	//system("pause");
	return 0;
}