#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define debug(a) cout << #a": " << a << endl;
#define mst(a, b) memset(a, b, sizeof(a))
#define ALL(x) x.begin(), x.end()
#define lc rt << 1
#define rc rt << 1 | 1
#define X first
#define Y second
inline int lowbit(int x) { return x & -x; }
typedef long long ll;
typedef long long LL;
typedef unsigned long long ULL;
typedef double db;
typedef pair<int*, int> pii;
typedef pair<int, LL> pil;
const int N = 5e4 + 10;
const int M = (1 << 10) + 10;
const int maxn = 2e3 + 10;
const int maxm = 4e3 + 10;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 998244353;
const db eps = 1e-5;



int main() {
#ifdef purple_bro
    freopen("in.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;

    cin >> T;

    for (; T--;) {
        int a, b;

        cin >> a >> b;

        if (__gcd(a, b) == 1)
            cout << "Finite" << "\n";
        else
            cout << "Infinite" << "\n";
    }


    return 0;
}
