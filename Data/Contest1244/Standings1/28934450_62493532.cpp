#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, n) FOR(i, 0, (n))
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define LAR(a, b) ((a)=max((a),(b)))
#define SML(a, b) ((a)=min((a),(b)))
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define ALL(a) (a).begin(), (a).end()
#ifdef LOCAL_DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

#define N 112345
int n; ll k;
ll a[N];
ll b[N]={};

int main(){
	scanf("%d%lld", &n, &k);
	REP(i, n) scanf("%lld", a+i);
	sort(a, a+n);
	// REP(i, n) b[i+1] = b[i] + a[i];
	REP(i, n) DEBUG("%lld ", a[i]); DEBUG("\n");
	REP(i, (n-1)/2){
		ll df = a[i+1]-a[i] + a[n-i-1] - a[n-i-2];
		ll cst = df * (i+1);
		DEBUG("[%d]%lld=>%lld, %lld<=%lld[%d]\n", i, a[i], a[i+1], a[n-i-2], a[n-i-1], n-i-2);
		DEBUG("cst = %lld, k = %lld\n", cst, k);
		if(cst <= k){
			k -= cst;
		} else {
			ll ans = a[n-i-1] - a[i];
			ans -= k / (i+1);
			printf("%lld\n", ans);
			return 0;
		}
	}
	ll ans = 0;
	if(n%2 == 0){
		ans = a[n/2] - a[n/2-1];
		ans -= min(k / (n/2), ans);
	}
	printf("%lld\n", ans);
}
