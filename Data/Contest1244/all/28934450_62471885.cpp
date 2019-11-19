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

int main(){
	ll n, p, w, d; scanf("%lld%lld%lld%lld\n", &n, &p, &w, &d);
	REP(y, 1<<20){
		ll a = p-y*d ;
		if( a % w ) continue;
		ll x = a / w;
		ll z = n-x-y;
		if(x < 0 || z < 0) continue;
		printf("%lld %d %lld\n", x, y, z);
		DEBUG(" = %lld (== %lld)\n", x*w+y*d, p);
		return 0;
	}
	printf("-1\n");
}
