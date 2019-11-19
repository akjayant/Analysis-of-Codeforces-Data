#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		ll n;
		cin >> n;
		ll p[n];
		ll cnt = 0;
		for(int i=0; i<n; i++) cin >> p[i], cnt += p[i]%2;
		ll m;
		cin >> m;
		ll q[m];
		ll cmt = 0;
		for(int i=0; i<m; i++) cin >> q[i], cmt += q[i]%2;
		ll ans = cnt*cmt + (n-cnt)*(m-cmt);
		cout << ans << endl;
	}
}