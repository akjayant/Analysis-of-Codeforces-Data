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
ll n, res, num, a[N], b[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef makacha
        freopen("m.inp", "r", stdin);
        freopen("m.out", "w", stdout);
    #endif // makacha
    cin >> n;
    ll m = sqrt(n);
    ll s = n;
    res = n;
    for (ll i = 2; i <= m; i++)
        if (s % i == 0) {
            while (s % i == 0)
                s /= i;
            a[++num] = i;
        }
    if (s > 1 && s != n)
        a[++num] = s;
    if (num >= 2)
        cout << 1;
    if (num == 1)
        cout << a[1];
    if (!num)
        cout << n;
}
