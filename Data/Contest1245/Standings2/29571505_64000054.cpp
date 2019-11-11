/* Bismillahirrahmanirrahim */
/* Author : Jehian Norman Saviero (@Reiva5) */
#include <bits/stdc++.h>
 
// MACROS SAMPAH
#define Jehian using
#define Norman namespace
#define Saviero std
 
Jehian Norman Saviero;
 
// MACROS TYPE
typedef long l;
typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<l,l> pl;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<l> vl;
typedef vector<ll> vll;
 
// MACROS FOR PRINT
#define nl printf("\n")
 
// MACROS FOR ATTRIBUTE
#define fi first
#define se second
 
// MACROS FOR FUNCTION AND METHOD
#define eb emplace_back
#define mp make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define ALL(x) (x).begin(), (x).end()
#define ALLN(x,n) (x), (x)+(n)
#define CUBE(x) (SQR(x)*(x))
#define SET(x,y) for (int _qwe = sizeof(x)/sizeof(x[0]); _qwe; ) x[--_qwe] = (y)
#define SQR(x) ((x)*(x))
#define SSORT(x,sz) sort(ALLN(x,sz))
#define RESET(x) memset((x), 0, sizeof(x))
#define VSORT(x) sort(ALL(x))
 
// MACROS READ INPUT
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%ld", &x)
#define scll(x) scanf("%lld", &x)
#define scd(x) scanf("%lf", &x)
#define scld(x) scanf("%Lf", &x)
#define scul(x) scl(x)
#define scull(x) scll(x)

int main() {
	int T;
	sci(T);
	while (T--) {
		int N;
		sci(N);
		int a, b, c;
		sci(a), sci(b), sci(c);
		string s;
		cin >> s;
		string ans = "";
		for (int i = 0; i < N; ++i) ans.pb('-');
		int win = 0;
		for (int i = 0; i < N; ++i) {
			if (s[i] == 'R' && b > 0) ans[i] = 'P', --b, ++win;
			if (s[i] == 'P' && c > 0) ans[i] = 'S', --c, ++win;
			if (s[i] == 'S' && a > 0) ans[i] = 'R', --a, ++win;
		}
		for (int i = 0; i < N; ++i) {
			if (ans[i] == '-') {
				if (a > 0) ans[i] = 'R', --a;
				else if (b > 0) ans[i] = 'P', --b;
				else ans[i] = 'S', --c;
			}
		}
		int batas = (N + 1)/2;
		if (win >= batas) {
			puts("YES");
			printf("%s\n", ans.c_str());
		} else {
			puts("NO");
		}
	}
	return 0;
}