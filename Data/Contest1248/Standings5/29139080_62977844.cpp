// !FromHere
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_cxx;

typedef double db;
typedef long long ll;
typedef pair<db, db> pdd;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef unsigned long long ull;

#define F          first
#define S          second
#define pnl        printf("\n")
#define sz(x)      (int)x.size()
#define sf(x)      scanf("%d",&x)
#define pf(x)      printf("%d\n",x)
#define all(x)     x.begin(),x.end()
#define rall(x)    x.rbegin(),x.rend()
#define rep(i, n)  for(int i = 0; i < n; ++i)

const db eps = 1e-9;
const db pi = acos(-1);
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000 * 1000 * 1000 + 7;

int t;
int n, m;
int a, b;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int e = 0, o = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a);
            if (a % 2 == 0) e++;
            else o++;
        }
        scanf("%d", &m);
        ll ans = 0;
        for (int i = 0; i < m; ++i) {
            scanf("%d", &a);
            if (a % 2 == 0) ans += e;
            else ans += o;
        }
        cout << ans << endl;
    }
    return 0;
}
