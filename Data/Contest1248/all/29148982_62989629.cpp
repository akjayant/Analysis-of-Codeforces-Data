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
// wb  12
ll dp[100005][2][2], ans[100005];

int main() {
    dp[1][0][0] = 1;
    dp[1][1][0] = 1;
    ans[1] = 2;
    for(ll i = 2; i <= 100000; ++i) {
        dp[i][0][0] = (dp[i-1][1][0]+dp[i-1][1][1])%mod;
        dp[i][0][1] = dp[i-1][0][0];
        dp[i][1][0] = (dp[i-1][0][0]+dp[i-1][0][1])%mod;
        dp[i][1][1] = dp[i-1][1][0];
        ans[i] = (dp[i][0][0]+dp[i][0][1]+dp[i][1][0]+dp[i][1][1])%mod;
    }
//    for(ll i = 1; i <= 10; ++i) printf("%lld --\n",ans[i]);
    ll n, m;
    scanf("%lld%lld",&n,&m);
    printf("%lld\n",(ans[n]+ans[m]-2+mod)%mod);
    return 0;
}

/*
1 4 6 10
6 +2+2
*/














