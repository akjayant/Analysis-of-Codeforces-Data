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
int a, b, c, d, k;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        int needA = (a + c - 1) / c;
        int needB = (b + d - 1) / d;
        if (needA + needB > k) {
            cout << -1 << endl;
            continue;
        }
        cout << needA << " " << needB << endl;
    }
    return 0;
}
