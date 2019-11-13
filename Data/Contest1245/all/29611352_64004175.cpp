/**
    *Makacha
**/
#include <bits/stdc++.h>
using namespace std;

template <typename T> inline void read (T &x) { bool b = 0; char c; while (!isdigit (c = getchar()) && c != '-');
if (c == '-') c = getchar(), b = 1; x = c - 48; while (isdigit(c = getchar())) x = (x << 3) + (x << 1) + c - 48; if (b) x = -x; }
template <typename T> inline void wrip(T x) { if (x > 9) wrip(x / 10); putchar(x%10 + 48); }
template <typename T> inline void write(T x) { if (x < 0) putchar('-'), x = -x; wrip(x);}
void reads(string &s) { char c; while (!isalpha(c = getchar())); s = c; while (isalpha(c = getchar())) s += c; }
typedef const int csint;

#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef double ld;

const ld pi = acos(-1);
const int mod = 1e9 + 7;
const int inf = 1e9 + 11;
const int N = 1e5 + 11;
typedef pair <int, int> ii;
int n, f[N];
string s;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef makacha
        freopen("m.inp", "r", stdin);
        freopen("m.out", "w", stdout);
    #endif // makacha
    cin >> s;
    n = s.size();
    s = '#' + s;
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1];
        if (s[i] == 'm') {
            cout << 0;
            return 0;
        }
        if (s[i] == 'w') {
            cout << 0;
            return 0;
        }
        if (s[i] == 'n' && s[i - 1] == 'n')
            f[i] = (f[i] + f[i - 2]) % mod;
        if (s[i] == 'u' && s[i - 1] == 'u')
            f[i] = (f[i] + f[i - 2]) % mod;
    }
    cout << f[n];
}
