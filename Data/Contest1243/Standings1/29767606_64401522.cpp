#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define pb push_back 
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n;
	vector<pair<ll, ll> > cur;
	ll x = n;
	for(ll i = 2; i * i <= n; i++){
		int ct = 0;
		while(x % i == 0){
			ct++;
			x /= i;
		}
		if(ct){
			cur.pb(mp(i, ct));
		}
	}
	if(x != 1)
		cur.pb(mp(x, 1));
	if(cur.size() == 1){
		cout << cur[0].first << '\n';
	}
	else cout << 1 << '\n';

}