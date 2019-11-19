#include<bits/stdc++.h>
using namespace std;
int t, n;
string s;

int main()
{
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--){
		cin >> n >> s;
		int ans = n;
		for (int i = 0; i < n; ++ i)
			if (s[i] == '1'){
				ans = max(ans, (i + 1) * 2);
				ans = max(ans, (n - i) * 2);
			}
		cout << ans << endl;
	}
	return 0;
}