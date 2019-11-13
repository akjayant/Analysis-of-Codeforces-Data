#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.in", "r", stdin); //freopen("output.txt", "w", stdout);
	int t , n;
	cin >> t;
	while(t-- && cin >> n){
		vector < int > v(n);
		for(int & i : v)
			cin >> i;
		sort(v.rbegin(), v.rend());
		int ans = 0;
		for(int i = 0; i < n; i++)
			ans = max(ans, min(i+1, v[i]));
		cout << ans << endl;
	}
	return 0;
}
