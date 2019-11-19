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
const int N = 4000010;
int n, m;
char s[N];
bool vis[N];
set<pii> st, tmp;

template<typename T> void gi(T &x) {
	x = 0; register char c = getchar(), pre = 0;
	for(; c < '0' || c > '9'; pre = c, c = getchar());
	for(; c >= '0' && c <= '9'; c = getchar()) x = x * 10ll + (c ^ 48);
	if(pre == '-') x = -x;
}
bool check() { rep(i, 2, n) if(s[i] == s[i - 1]) return 0; return 1; }
int main() {
	scanf("%d%d", &n, &m), scanf("%s", s + 1);
	if(n % 2 == 0 && check()) {
		m %= 2;
		rep(i, 1, n) printf("%c", ((s[i] == 'B') ^ m) ? 'B' : 'W');
		return 0;
	}
	rep(i, n + 1, n + n) s[i] = s[i - n];
	for(int i = 1, j; i <= n;) {
		j = i; for(; j - i + 2 <= n && s[j + 1] == s[j]; ++j);
		if(i < j) { rep(k, i, j) vis[(k - 1) % n + 1] = 1; }
//		printf(">>> %d %d\n", i, j);
		if(i < j) st.insert(mp(i, (j - 1) % n + 1));
		i = j + 1;
	}
	rep(i, 1, m) {
		if(st.empty()) break;
		for(auto v : st) {
			int lb = (v.fst - 2 + n) % n + 1, rb = v.snd % n + 1;
//			printf(">>> %d %d %d %d\n", lb, v.fst, v.snd, rb);
			if(vis[lb] && vis[rb]) continue;
			if(!vis[lb]) s[lb] = s[v.fst];
			if(!vis[rb]) s[rb] = s[v.fst];
			vis[lb] = vis[rb] = 1;
			if(s[rb] != s[v.snd]) rb = v.snd;
			if(s[lb] != s[v.fst]) lb = v.fst;
			tmp.insert(mp(lb, rb));
		}
		st = tmp, tmp.clear();
	}
	m %= 2;
	rep(i, 1, n) {
		if(vis[i]) printf("%c", s[i]);
		else printf("%c", ((s[i] == 'B') ^ m) ? 'B' : 'W');
	}
	return 0;
}