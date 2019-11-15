#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false)
#define popcnt __builtin_popcount
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb emplace_back
#define pii pair<int,int>
#define all(n) (n).begin(),(n).end()
#define rep(i,a,n) for (int i = a; i <= n; i++)
#define QAQ sort(co+1,co+1+n)
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
const int maxn = 3e5 + 5;
const ll mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
ll pow_mod(ll a,ll b,ll c=mod,ll ans=1){while(b){if(b&1) ans=(a*ans)%c;a=(a*a)%c,b>>=1;}return ans;}
ll co[maxn], dp[maxn];

string str;
ll n, m, k, t, d;
vector<ll>ff;
int main() {
	IO;
	cin >> str;
	str = " " + str;
	dp[0] = 1;
	for(int i = 1; i < str.size(); i++){
		if(str[i] == 'w' || str[i] == 'm'){
			cout << 0;
			return 0;
		
		}
		else if(str[i] == 'u' && str[i-1] == 'u' || str[i] == 'n' && str[i-1] == 'n')
			dp[i] = dp[i-1] + dp[i-2], dp[i] %= mod;
		else
			dp[i] = dp[i-1];
//		cout << dp[i] << " ";
	}
	cout << dp[str.size()-1];
}
