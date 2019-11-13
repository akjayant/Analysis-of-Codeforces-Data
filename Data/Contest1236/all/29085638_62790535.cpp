#include <bits/stdc++.h>
 
using namespace std;
 
#define sc(a) scanf("%d",&a)
#define sc2(a,b) sc(a), sc(b)
#define sc3(a,b,c) sc2(a, b), sc(c)
#define pri(x) printf("%d\n",x)
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define BUFF ios::sync_with_stdio(0)
#define prif() printf("\n")
#define prie(x) printf("%d ", x)
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9+7;

ll expo(ll a, ll b) {
	if (!b) return 1;
	ll ans = expo(a*a%MOD, b/2);
	if (b%2) ans = a*ans%MOD;
	return ans;
}

int main() {
	int n, m; sc2(n, m);
	ll p = expo(2, m);
	p = (p+MOD-1)%MOD;
	ll ans = expo(p, n);
	printf("%lld\n", ans);
	exit(0);
}
