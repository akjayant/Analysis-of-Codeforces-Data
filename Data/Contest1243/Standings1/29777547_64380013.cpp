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
int n, ans, a[N];
string s, t;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef makacha
        freopen("m.inp", "r", stdin);
        freopen("m.out", "w", stdout);
    #endif // makacha
    int ntest;
    cin >> ntest;
    while (ntest--) {
        cin >> n >> s >> t;
        s = '#' + s;
        t = '#' + t;
        int pos1 = 0, pos2 = 0;
        for (int i = 1; i <= n; i++)
            if (s[i] != t[i]) {
                pos1 = i;
                break;
            }
        for (int i = n; i > 0; i--)
            if (t[i] != s[i]) {
                pos2 = i;
                break;
            }
        swap(s[pos1], t[pos2]);
        for (int i = 1; i <= n; i++)
            if (s[i] != t[i])
                goto line;
        cout << "YES\n";
        continue;
        line:;
        cout << "NO\n";
        continue;
    }
}
