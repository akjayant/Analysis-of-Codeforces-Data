# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = (int) 1e5 + 1;

ll n;
vector < ll > h;
int main(){
	cin >> n;
	if(n == 1){
		cout << 1;
		return 0;
	}
	for(ll i = 1; i * i <= n; i++){
		if(n % i == 0){
			h.push_back(i);
			h.push_back(n / i);
		}		
	}
	sort(h.begin(), h.end());
	h.resize(unique(h.begin(), h.end()) - h.begin());
	reverse(h.begin(), h.end());
	h.pop_back();
	ll ans = h[0];
	for(ll i : h){
		ans = __gcd(ans, i);
	}
	cout << ans;
	return 0;
}