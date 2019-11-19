#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define N 100005
#define M 100005
#define INF 0x3f3f3f3f
#define mk(x) (1<<x) // be conscious if mask x exceeds int
#define sz(x) ((int)x.size())
#define mp(a,b) make_pair(a, b)
#define endl '\n'
#define lowbit(x) (x&-x)

using namespace std;
typedef long long ll;
typedef double db;

/** fast read **/
template <typename T>
inline void read(T &x) {
    x = 0; T fg = 1; char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') fg = -1;
        ch = getchar();
    }
    while (isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    x = fg * x;
}
template <typename T, typename... Args>
inline void read(T &x, Args &... args) { read(x), read(args...); }

ll a[N];
unordered_map <ll, ll> mcnt;
vector <ll> v;
int main()
{
    int n; ll k;
    read(n, k);
    for (int i = 1; i <= n; i++) {
        read(a[i]);
        v.push_back(a[i]);
        mcnt[a[i]]++;
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int pl = 0, pr = sz(v)-1;
    ll vall = v[pl], valr = v[pr];
    ll cntl = mcnt[vall], cntr = mcnt[valr];

    ll _min = vall, _max = valr;
    while (pl < pr && k > 0) {
        vall = v[pl], valr = v[pr];
        if (cntl < cntr) {
            // pl+
            ll vallr = v[pl+1];
            ll cutk = (vallr - vall) * cntl;
            if (k >= cutk) {
                k -= cutk;
                pl++;
                cntl += mcnt[vallr];
                _min = vallr;
            }
            else {
                ll add = k / cntl;
                k = 0;
                _min += add;
            }
        }
        else if (cntl >= cntr) {
            ll valrl = v[pr-1];
            ll cutk = (valr - valrl) * cntr;
            if (k >= cutk) {
                k -= cutk;
                pr--;
                cntr += mcnt[valrl];
                _max = valrl;
            }
            else {
                ll add = k / cntr;
                k = 0;
                _max -= add;
            }
        }
    }

    ll ans = _max - _min;
    cout << ans << endl;

    return 0;
}
