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
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
LL qpow(LL x, LL y, LL MOD) {LL a=1; while(y){ if(y&1) a=a*x%MOD; x=x*x%MOD; y>>=1; } return a;}

char s[110], ans[110];
int main() {
    int T; scanf("%d", &T);
    while(T--) {
        int n, a, b, c;
        scanf("%d%d%d%d", &n, &a, &b, &c);
        scanf("%s", s);
        rep(i, 0, n-1) ans[i] = '#';
        int cnt = 0, m = 0;
        rep(i, 0, n-1) {
            if(s[i] == 'R') {
                if(b) ans[i] = 'P', cnt++, b--;
            } else if(s[i] == 'P') {
                if(c) ans[i] = 'S', cnt++, c--;
            } else {
                if(a) ans[i] = 'R', cnt++, a--;
            }
        }
        rep(i, 0, n-1) {
            if(ans[i] == '#') {
                if(a) ans[i] = 'R', a--;
                else if(b) ans[i] = 'P', b--;
                else ans[i] = 'S', c--;
            }
        }
        ans[n] = '\0';
        if(cnt >= (n+1)/2) {
            puts("YES");
            printf("%s\n", ans);
        } else puts("NO");
    }

    return 0;
}