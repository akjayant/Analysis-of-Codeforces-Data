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


lint MOD = 1e9 + 7;

void solve() {
    lint n;
    cin >> n;
    vector<int> arr(n * n);
    vector<vector<int>> answer(n);
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                arr[cur + j] = j;
            }
        } else {
            for (int j = 0; j < n; j++) {
                arr[cur + j] = n - 1 - j;
            }
        }
        cur += n;
    }
    /*for (int i = 0; i < n * n; i++) {
        cout << arr[i] << " ";
    }*/
    // cout << endl;
    for (int i = 0; i < n * n; i++) {
        answer[arr[i]].push_back(i + 1);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
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
    test = 1;
    //cin >> test;
    for (int i = 0; i < test; i++) {
        if (stress) {} else {
            solve();
        }
    }
    return 0;
}
