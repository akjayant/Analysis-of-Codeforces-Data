#include <bits/stdc++.h>

#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")

#define F first
#define S second
#define pb push_back
#define llong  long long
#define int llong
#define ld long double
#define endl '\n'


//#ifdef ARINOCHKA
//const int N = 500 + 100;
//const int M = 100 + 2 + 1;
//#else
//#endif

//#define cerr if (0) cerr


using namespace std;
using namespace __gnu_pbds;


mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());


const int N = 1e6 + 6;
const int M = 1e6 + 2 + 1;
const int B = 2100;
const int add1 = 39;
const llong per = 1e10;
const llong INF = 1e10;
const int MOD = 998244353;
const int MOD1 = 1e9 + 7;
const int rx[4] = {0, 1, -1, 0};
const int ry[4] = {1, 0, 0, -1};
const char rr[5]= {'5', 'N', 'E', 'S', 'W'};
template <typename T> using ordered_set = tree <T, null_type, less< T >, rb_tree_tag,tree_order_statistics_node_update>;





main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
//    freopen("bath.in", "r", stdin);
//    freopen("bath.out", "w", stdout);
#endif
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a = 0;
        int b = 0;
        int c = 0;
        int  d = 0;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            if (x % 2) a++;
            else b++;
        }
        int m;
        cin >> m;
        for(int i = 0; i < m; i++){
            int x;
            cin >> x;
            if (x % 2) c++;
            else d++;
        }

        int ans = a * c + b * d;
        cout << ans << endl;
    }


    return 0;
}
