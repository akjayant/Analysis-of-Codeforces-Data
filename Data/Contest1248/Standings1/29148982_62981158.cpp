#include <bits/stdc++.h>
using namespace std;
void debug() { cout << endl; }
template <class T, class ...R> void debug (T f, R ...r) { cout << "[" << f << "]"; debug (r...); }
template <class T> T mmin(T a, T b) { return min(a,b); }
template <class T, class ...R> T mmin(T a, R... b) { return min(a,mmin(b...)); }
template <class T> T mmax(T a, T b) { return max(a,b); }
template <class T, class ...R> T mmax(T a, R... b) { return max(a,mmax(b...)); }
template <class T> T mgcd(T a, T b) { return __gcd(a,b); }
template <class T, class ...R> T mgcd(T a, R... b) { return __gcd(a,mgcd(b...)); }

void myin()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
}

namespace IO
{
const int MX = 4e7;
char buf[MX];
int c, sz;
void begin()
{
    c = 0;
    sz = fread(buf, 1, MX, stdin);
}
inline bool read(int &t)
{
    while(c < sz && buf[c] != '-' && (buf[c] < '0' || buf[c] > '9')) c++;
    if(c >= sz) return false;
    bool flag = 0;
    if(buf[c] == '-') flag = 1, c++;
    for(t = 0; c < sz && '0' <= buf[c] && buf[c] <= '9'; c++) t = t * 10 + buf[c] - '0';
    if(flag) t = -t;
    return true;
}
}

#define ll long long
#define _p pair<ll, ll>
#define all(x) x.begin(), x.end()
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
#define fi first
#define se second

const ll N = 100005;
const ll M = 1e5+5;
const ll mod = 1e9+7;

ll a[100005];

int main() {
    ll n;
    scanf("%lld",&n);
    for(ll i = 1; i <= n; ++i) scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    ll r = n, l = 1, f = 0, al = 0, ar = 0;
    while(l <= r) {
        if(f == 0) ar += a[r--];
        else al += a[l++];
        f ^= 1;
    }
//    printf("%lld %lld -\n",)
    printf("%lld\n",al*al+ar*ar);
    return 0;
}

/*
2

1 4
2 3

3

1 6 7
2 5 8
3 4 9
*/














