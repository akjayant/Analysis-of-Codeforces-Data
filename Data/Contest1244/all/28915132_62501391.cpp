#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define pb push_back
#define N 100010 
using namespace std;
ll suf[N], pref[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, k;
	cin >> n >> k;
	vector<ll> df;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		df.pb(x);
	}
	sort(df.begin(), df.end());
	pref[0] = df[0];
	for(int i = 1; i < n; i++){
		pref[i] = pref[i - 1] + df[i];
	}
	suf[n - 1] = df[n - 1];
	for(int  i = n - 2; i >= 0; i--){
		suf[i] = suf[i + 1] + df[i];
	}
	ll mini = 1e18;
	for(int i = 0; i < n; i++){
		ll cur = k;
		cur -= (i + 1) * df[i] - pref[i];
		if(cur >= 0){
			ll low = df[i], high = df[n - 1] + 1;
			while(low < high){
				ll mid = (low + high) / 2;
				ll ind = lower_bound(df.begin(), df.end(), mid) - df.begin();
				ll rem = cur - (suf[ind] - (n - ind) * mid);
				if(rem >= 0)
					high = mid;
				else low = mid + 1;
			}
			if(low != df[n - 1] + 1){
				mini = min(mini, low - df[i]);
			}
		}
		cur = k;
		cur -= (suf[i] - (n - i) * df[i]);
		if(cur >= 0){
			ll low = 0, high = df[i] + 1;
			while(low < high){
				ll mid = (low + high) / 2;
				ll ind = lower_bound(df.begin(), df.end(), mid) - df.begin();
				ind--;
				ll rem = cur - ((ind + 1) * mid - pref[ind]);
				if(rem < 0)
					high = mid;
				else low = mid + 1;
			}
			if(low != df[i] + 1){
				mini = min(mini, df[i] - (low - 1));
			}
		}
	}
	cout << mini << '\n';

}