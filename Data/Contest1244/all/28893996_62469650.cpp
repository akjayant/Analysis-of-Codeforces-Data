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
int n;
char s[N]; int l, r;

template<typename T> void gi(T &x) {
	x = 0; register char c = getchar(), pre = 0;
	for(; c < '0' || c > '9'; pre = c, c = getchar());
	for(; c >= '0' && c <= '9'; c = getchar()) x = x * 10ll + (c ^ 48);
	if(pre == '-') x = -x;
}
void solve() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	l = r = -1;
	rep(i, 1, n) if(s[i] == '1') r = i;
	per(i, n, 1) if(s[i] == '1') l = i;
	if(l == -1 && r == -1) { printf("%d\n", n); return ; }
	int ans = n;
	ans = max(ans, r + r), ans = max(ans, n - l + 1 + n - l + 1);
	printf("%d\n", ans);
}
int main() {
	for(gi(T); T; --T) solve();
	return 0;
}