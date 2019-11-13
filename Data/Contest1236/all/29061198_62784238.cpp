#include <bits/stdc++.h>
using namespace std; typedef long long ll;
typedef vector<int> vi; typedef pair<int,int> pii;
const ll MOD = 1e9+7;

int main() { ios_base::sync_with_stdio(0);cin.tie(0);
	int t;
	cin >> t;
	for (int t1=0; t1<t; ++t1) {
	  int a,b,c,ans=0;
	  cin >> a >> b >> c;
	  ans += min(b,c/2);
	  b -= ans;
	  ans += min(a,b/2);
	  cout << 3*ans << '\n';
	}
	return 0;
}