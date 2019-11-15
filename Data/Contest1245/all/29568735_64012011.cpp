#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> pii;
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for(int i = int(b); i >= int(a); --i)
#define mem(x, y) memset(x, y, sizeof(x))
#define all(x) (x).begin(),(x).end()
#define SZ(x) x.size()
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const LL INF = 1e18;
const int inf = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int N = 1e5 + 10;
LL qpow(LL x, LL y, LL MOD) {LL a=1; while(y){ if(y&1) a=a*x%MOD; x=x*x%MOD; y>>=1; } return a;}

LL dp[N];
char s[N];
int main() {
    dp[0] = dp[1] = 1;
    rep(i, 2, N-1) dp[i] = (dp[i-1] + dp[i-2]) % mod;
    LL ans = 1;
    scanf("%s", s);
    int n = strlen(s);
    int cnt = 0;
    char cur = '#';
    rep(i, 0, n-1) {
        if(s[i] == 'm' || s[i] == 'w') {
            puts("0");
            return 0;
        }
        if(s[i] == 'u') {
            if(cur == 'u') cnt++;
            else {
                ans = ans*dp[cnt]%mod;
                cnt = 1;
                cur = s[i];
            }
        } else if(s[i] == 'n') {
            if(cur == 'n') cnt++;
            else {
                ans = ans*dp[cnt]%mod;
                cnt = 1;
                cur = s[i];
            }
        } else {
            ans = ans*dp[cnt]%mod;
            cnt = 0;
            cur = s[i];
        }
    }
    ans = ans*dp[cnt]%mod;
    printf("%lld\n", ans);

    return 0;
}