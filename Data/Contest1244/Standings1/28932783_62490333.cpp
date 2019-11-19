#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll ; 
typedef long double ld ;
typedef pair<ll , ll> pll ;

const ll N = 2e5 + 30 , Mod = 1e9 + 7 ;
const ll SQ = 330 ;

set<ll> s ;
map<ll , ll> cnt;
int main () {
    ios::sync_with_stdio(0), cin.tie(0) ;
    ll n , k ;
    cin >> n >> k ;
    for (int i = 0 ; i < n ; i ++) {
    	ll x ;
    	cin >> x ;
    	cnt[x] ++ ;
    	s.insert(x) ;
	}
	while (s.size() >= 3) {
		ll mn = *s.begin() ;
		s.erase(mn) ;
		ll md = *s.begin() ;
		ll mx = *s.rbegin() ;
		s.erase(mx) ;
		ll md2 = *s.rbegin() ;
		s.erase(md) ;
		s.erase(md2) ;
		s.erase(md2) ;
		if (cnt[mn] <= cnt[mx]) {
			ll res = md - mn ;
			if (k < cnt[mn]) {
				s.insert(mx) ;
				s.insert(md) ;
				s.insert(mn) ;
				s.insert(md2) ;
				break;
			}
			ll x = min(res , k / cnt[mn]) ;
			k -= cnt[mn] * x ;
			cnt[mn + x] += cnt[mn] ;
			cnt[mn] = 0 ;
			s.insert(mn + x) ;
			s.insert(mx) ;
			s.insert(md2) ;
			s.insert(md) ;
		}
		else {
			ll res = mx - md2 ;
			if (k < cnt[mx]) {
				s.insert(mx) ;
				s.insert(md) ;
				s.insert(mn) ;
				s.insert(md2) ;
				break;
			}
			ll x = min(res , k / cnt[mx]) ;
			k -= cnt[mx] * x ;
			cnt[mx - x] += cnt[mx] ;
			cnt[mx] = 0 ;
			s.insert(mx - x) ;
			s.insert(mn) ;
			s.insert(md) ;
			s.insert(md2);
		}
		
	}
	if (s.size() == 1) cout << 0 ;
	else {
		ll ans = *(s.rbegin()) - *(s.begin()) ;
		if (s.size() == 2) {
			ll bb = *s.rbegin() ;
			ll ss = *s.begin() ;
			ll res = min(cnt[bb] , cnt[ss]) ;
			ll m = bb - ss ;
			ll gg = min(m , k / res) ;
			ans = min(ans , bb - ss - gg) ;
		}
		cout << ans ;
	}
    return (0) ;
}
