#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	iostream::sync_with_stdio(0);
	int t;
	cin>>t;
	for (; t; t--) {
		int n;
		cin>>n;
		string s;
		cin>>s;
		int res = n;
		for (int i = 0; i < n; i++)
			if (s[i] == '1') res = max(res, max(2 * (i + 1), 2 * (n - i)));
		cout<<res<<endl;
	}
}