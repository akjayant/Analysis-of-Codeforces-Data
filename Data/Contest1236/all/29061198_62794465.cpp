#include <bits/stdc++.h>
using namespace std; typedef long long ll;
typedef vector<int> vi; typedef pair<int,int> pii;
const ll MOD = 1e9+7;

int main() { ios_base::sync_with_stdio(0);cin.tie(0);
	int n, cur;
	cin >> n; cur = n*n+1;
	vector<vi> ans(n);
	while (cur > 1) {
	  for (int i=0; i<n; ++i) ans[i].push_back(--cur);
	  if (cur <= 1) break;
	  for (int i=n-1; i>=0; --i) ans[i].push_back(--cur);
	}
	for (int i=0; i<n; ++i) {
	  for (int v:ans[i]) cout << v << ' ';
	  cout << '\n';
	}
	return 0;
}