#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 998244353;
const int N = 1000010;
ll n, p, w, d, x, y, z; bool flag;

template<typename T> void gi(T &x) {
	x = 0; register char c = getchar(), pre = 0;
	for(; c < '0' || c > '9'; pre = c, c = getchar());
	for(; c >= '0' && c <= '9'; c = getchar()) x = x * 10ll + (c ^ 48);
	if(pre == '-') x = -x;
}
int main() {
	gi(n), gi(p), gi(w), gi(d);
	if(n * w < p) { puts("-1"); return 0; }
	if(!p) { printf("0 0 %lld\n", n); return 0; }
	for(ll i = 0; i <= w; i++) {
		if(i * d > p) continue;
		ll del = p - i * d;
		if(del % w == 0) {
			x = del / w, y = i, z = n - x - y; if(z < 0) continue;
			printf("%lld %lld %lld\n", x, y, z); return 0;
		}
	}
	puts("-1");
	return 0;
}