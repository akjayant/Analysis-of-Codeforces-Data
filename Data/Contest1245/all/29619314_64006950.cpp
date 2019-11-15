#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>  
#define ll long long
#define ff first 
#define ss second
#define pb push_back
#define rep(i,a,b)  for (__typeof((b)) i=(a);i<=(b);i++)
#define nrep(i,a,b)  for (__typeof((b)) i=(b);i>=(a);i--)
#define all(a) (a).begin(),(a).end()
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
const ll N = 1e5 + 5;
const ll N1 = 3e5 + 5;
const int LOGN = 17;
const ll mod = 1e9 + 7;

ll power(ll a, ll b, ll c) {
	ll ret = 1;
	while(b > 0) {
		if(b%2 == 1)
			ret = (ret * a)%c;
		b /= 2;
		a = (a * a)%c;
	}
	return ret;
}

ll fib[N + 5];

void pre() {
	fib[1] = fib[0] = 1;
	for(int i=2;i<N;i++)
		fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
}

int main() {
	
	pre();
	int n;
	string s;
	cin >> s;
	n = s.size();

	int dp[n + 3], ct = 0;
	ll ans = 1;
	char pre = 'a';
	dp[0] = 1;

	for(int i=0;i<n;i++) {

		if(s[i] == 'm' or s[i] == 'w') {
			cout << "0\n";
			return 0;
		}

		if(s[i] == 'u') {
			if(ct > 0 and pre != s[i]) {
				ans = (ans * fib[ct])%mod;
				ct = 1;
				pre = s[i];
				continue;
			}

			if(ct == 0)
				pre = s[i];
			
			ct++;
		}
		else if(s[i] == 'n') {

			if(ct > 0 and pre != s[i]) {
				ans = (ans * fib[ct])%mod;
				ct = 1;
				pre = s[i];
				continue;
			}

			if(ct == 0)
				pre = s[i];
			
			ct++;
		}
		else {
			if(ct > 0) {
				ans = (ans * fib[ct])%mod;
			}
			ct = 0;
			pre = s[i];
		}

	}

	if(ct > 0) {
		ans = (ans * fib[ct])%mod;
	}
	cout << ans << endl;

	return 0;
}
