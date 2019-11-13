#pragma GCC omptimize("unroll-loops")
#pragma optimize("SEX_ON_THE_BEACH")
#pragma GCC optimize("no-stack-protector")
#pragma comment(linker, "/STACK:1000000000")

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <utility>
#include <vector>

using namespace std;

using lint = int64_t;
using ldd = long double;

const int MOD = 998244353;
const lint INF = 1e18;

#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second


#ifdef HOME_
    int jjj;
    #define PO cout << "Pomelo" << endl;
    #define OL cout << "Oliva" << endl;

    #define debug(x) cout << #x << " " << x << endl;
    #define debug_p(x) cout << #x << " " << x.ff << " " << x.ss << endl;
    #define debug_v(x) cout << #x << " "; for (auto iii : x) cout << iii << " "; cout << endl;
    #define debug_vp(x) cout << #x << " "; for (auto ii : x) cout << '[' << ii.ff << " " << ii.ss << ']'; cout << endl;
    #define say(x) cout << x << endl;
#else
    #define PO 0;
    #define OL 0;

    #define debug(x) 0;
    #define debug_p(x) 0;
    #define debug_vp(x) 0;
    #define debug_v(x) 0;
    #define debug_vp(x) 0;
    #define say(x) 0;
#endif // HOME

void solve() {
    int a, b, c;
    cin >>a >> b >> c;
    int ans = 0;
    while ((c > 1) && (b > 0)) {
        ans++;
        c -= 2;
        b--;
    }
    while ((a > 0) && (b > 1)) {
        ans++;
        b -= 2;
        a--;
    }
    cout << ans * 3 << endl;
}

void stupidsolve() {

}
void generator() {}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int stress = 0;
    int test;
    //int test = 1;
    cin >> test;
    for (int i = 0; i < test; i++) {
        if (stress) {} else {
            solve();
        }
    }
    return 0;
}
