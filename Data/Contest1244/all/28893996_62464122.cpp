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
int T;
int a, b, c, d, k;

template<typename T> void gi(T &x) {
	x = 0; register char c = getchar(), pre = 0;
	for(; c < '0' || c > '9'; pre = c, c = getchar());
	for(; c >= '0' && c <= '9'; c = getchar()) x = x * 10ll + (c ^ 48);
	if(pre == '-') x = -x;
}
void solve() {
	gi(a), gi(b), gi(c), gi(d), gi(k);
	rep(i, 1, k) rep(j, 1, k) {
		if(i + j > k) continue;
		if(i * c >= a && j * d >= b) {
			printf("%d %d\n",i, j); return ;
		}
	}
	puts("-1");
}
int main() {
	for(gi(T); T; --T) solve();
	return 0;
}