#include <bits/stdc++.h>
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
long long Rand(long long L, long long R) {return L + rd() % (R - L + 1);}
long long MUL(long long A, long long B, long long MOD) {long long r = 0;while (B) {r = (r + (A * (B % 2) % MOD)) % MOD;A = (A + A) % MOD;B /= 2;}return r;}
long long POW(long long A, long long B, long long MOD) {long long RES = 1;A %= MOD;assert(B >= 0);for(; B; B >>= 1) {if (B & 1) RES = MUL(RES, A, MOD);A = MUL(A, A, MOD);}return RES;}
long long GCD(long long A, long long B) {return B == 0 ? A : GCD(B, A % B);}
int dx[] = {0, -1, 0, 1, 0};
int dy[] = {0,  0, 1, 0,-1};
#define __gcd GCD
#define in ({int x=0,n=0,c=getchar();for(;!isdigit(c);c=getchar())n=(c=='-');for(;isdigit(c);c=getchar())x=x*10+c-'0';(n)?-x:x;})
#define inc ({char c=0;for(;c=='\n'||c==' ';c=getchar());c=getchar();c;})
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define ii pair <int, int>
#define fi first
#define se second
#define pb push_back
#define ll long long
#define ull unsigned long long
#define db double
#define vi vector <int>
#define vii vector <ii>
#define reset(f, x) memset(f, x, sizeof(f))
#define all(v) v.begin(), v.end()
#define bit(mask, i) (mask & (1ll << i))
#define onbit(mask, i) (mask | (1ll << i))
#define offbit(mask, i) (mask &~ (1ll << i))
#define sz(v) (int) v.size()
#define bug1(a) cout << #a << " = " << a << ";"
#define bug1l(a) cout << #a << " = " << a << ";" << '\n'
#define bug2(a, b) cout << #a << " = " << a << "; " << #b << " = " << b << "; "
#define bug2l(a, b) cout << #a << " = " << a << "; " << #b << " = " << b << ";" << '\n'
#define bug3(a, b, c) cout << #a << " = " << a << "; " << #b << " = " << b << "; " << #c << " = " << c << "; "
#define bug3l(a, b, c) cout << #a << " = " << a << "; " << #b << " = " << b << ";" << #c << " = " << c << "; " << '\n'
#define bug4(a, b, c, d) cout << #a << " = " << a << "; " << #b << " = " << b << "; " << #c << " = " << c << "; " << #d << " = " << d << "; "
#define bug4l(a, b, c, d) cout << #a << " = " << a << "; " << #b << " = " << b << ";" << #c << " = " << c << "; " << #d << " = " << d << "; " << '\n'
#define FASTIOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define TASK "1245A"
int t;
main() {
	FASTIOS;
#ifndef ONLINE_JUDGE
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
#endif

    t = in;
    while (t--) {
        int a, b;
        a = in, b = in;
        if (__gcd(a, b) == 1)
            cout << "Finite" << '\n';
        else cout << "Infinite" << '\n';
    }
	return 0;
}
