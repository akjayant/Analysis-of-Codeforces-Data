#include <bits/stdc++.h>
#include<random>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
const int M = 20;
#define lowbit(x) (x&(-x))
const int inf = 0x3f3f3f3f;
const ll INF = 100000000000000000;
const int mod = 998244353;
typedef pair<int, int> P;
#define eps 1e-6
ll n, p, w, d;
ll gcd(ll a, ll b)
{
	if (!b) return a;
	return gcd(b, a%b);
}
int vis[N];
int main()
{
	cin >> n >> p >> w >> d;
	ll g = gcd(w, d);
	if (p%g != 0){
		return 0 * puts("-1");
	}
	ll x = 0;
	for (;x*d<=p; ++x){
		int gg = (x*d) % w;
		if (gg == p%w){
			break;
		}
		if (vis[gg]){
			return 0 * puts("-1");
		}
		vis[gg] = 1;
	}
	if (x*d>p) return 0 * puts("-1");
	ll y = (p - x*d) / w ;
	ll z = n - x - y;
	if (z<0 || x<0 || y<0) return 0 * puts("-1");
	printf("%lld %lld %lld\n", y, x, z);
	return 0;
}
/*

*/