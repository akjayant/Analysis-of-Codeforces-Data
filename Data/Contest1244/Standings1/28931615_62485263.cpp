#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

typedef  long long  int ll;
typedef  long double ld;

#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define rev(i,a,b) for(ll i=a;i>=b;i--)
#define pll pair<ll,ll>
#define vll vector<ll>
#define sll set<ll>
#define vpll vector<pll>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define ln length()
#define M 1000000007
ll n,k,a[100004],pr[100005],sf[100004];

ll compute(ll st, ll en) {
	ll tot = 0;	
	ll psl = lower_bound(a+1,a+n+1,st) - a;
	tot += (psl-1)*st - pr[psl-1];

	ll psr = lower_bound(a+1,a+n+1,en+1) - a;
	tot += sf[psr] - (n-psr+1)*en;

	return tot;
}

bool possible(ll diff ) {
	ll cost = 1e17;
	rep(i,1,n) {
		cost = min(cost,compute(a[i],a[i]+diff));
		cost = min(cost,compute(a[i]-diff,a[i]));
		if(cost <= k ) return true;
	}	
	return false;
}

int main() {
    ios :: sync_with_stdio(false); cin.tie(0);
    cin>>n>>k;
    rep(i,1,n) cin>>a[i];

    sort(a+1,a+n+1);
    rep(i,1,n) pr[i] = pr[i-1] + a[i];
    rev(i,n,1) sf[i] = sf[i+1] + a[i];

    ll lo=0, hi = a[n]-a[1],mid,ans;
    while(lo <= hi) {
    	mid = (lo + hi)/2;
    	if(possible(mid)) {
    		ans = mid;
    		hi = mid - 1;

    	}
    	else lo = mid + 1;
    }
    cout<<ans<<'\n';
}
