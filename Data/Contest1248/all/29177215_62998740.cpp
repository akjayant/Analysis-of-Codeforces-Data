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

int t[4 * N];
int add[4 * N];

void push(int v){
    if (add[v]){
        add[v * 2] = max(add[v], add[v * 2]);
        add[v * 2 + 1] = max(add[v], add[v * 2 + 1]);
        t[v * 2] = max(t[v * 2], add[v * 2]);
        t[v * 2 + 1] = max(t[v * 2 + 1], add[v * 2 + 1]);
        add[v] = 0;
    }
}

void upd(int v, int cl, int cr, int l, int r, int x){
 if (cl > r || cr < l) return;
    if (l <= cl && cr <= r){
        t[v] = max(t[v], x);
        add[v] = max(x, add[v]);
        return;
    }
    push(v);
    int mid = (cl + cr) / 2;
    upd(v * 2, cl, mid, l, r, x);
    upd(v * 2 + 1, mid + 1, cr, l, r, x);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
}

int go(int v, int cl, int cr){
    if (cl == cr) return cr;
    push(v);
    int mid = (cl + cr) / 2;
    if (t[v * 2] <= t[v * 2 + 1]){
        return go(v * 2, cl, mid);
    }
    return go(v * 2 + 1, mid + 1, cr);
}


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
    int n, add;
    cin >> n >> add;
    int p = 1;
    while(p < n) p *= 2;
    for(int  i = 0; i < p + p; i++){
        t[i] = 1e18;
    }
    vector <int> a;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        t[i + p] = x;
    }

    for(int i = p - 1; i; i--){
        t[i] = min(t[i * 2], t[i * 2 + 1]);
    }

    vector <int> ot(n);
    int last = 0;

    while(n--){
        int v = go(1, 0, p - 1);
//        cerr << v << endl;
        last = max(last, t[v + p]);
        ot[v] = last + add;
        upd(1, 0, p - 1, v, v, 1e18);
        upd(1, 0, p - 1, v, p - 1, ot[v]);
        last = ot[v];
    }
    for(int to : ot) cout << to << ' ';;

    return 0;
}
