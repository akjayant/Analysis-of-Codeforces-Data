#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define pb push_back 
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<ll> df;
	for(int i = 0; i < n; i++){
		ll x;
		cin >> x;
		df.pb(x);
	}
	sort(df.begin(), df.end());
	reverse(df.begin(), df.end());
	ll ans = 0, cur = 0;
	for(int i = 0; i < (n + 1) / 2; i++){
		cur += df[i];
	}
	ans += cur * cur;
	cur = 0;
	for(int i = (n + 1) / 2; i < n; i++){
		cur += df[i];
	}
	ans += cur * cur;
	cout << ans << '\n';


}
