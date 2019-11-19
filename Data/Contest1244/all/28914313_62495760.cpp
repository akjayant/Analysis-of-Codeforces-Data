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


#ifdef ARINOCHKA
const int N = 1 + 100;
#else
#define cerr if(0) cerr
const int N = 1e5 + 1;
#endif




using namespace std;
using namespace __gnu_pbds;


mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());


const int M = 16 + 5;
const int B = 2100;
const int add1 = 39;
const llong per = 1e10;
const llong INF = 1e10;
const int MOD1 = 998244353;
const int MOD = 1e9 + 7;
const int rx[4] = {0, 1, -1, 0};
const int ry[4] = {1, 0, 0, -1};
const char rr[5]= {'5', 'N', 'E', 'S', 'W'};
template <typename T> using ordered_set = tree <T, null_type, less< T >, rb_tree_tag,tree_order_statistics_node_update>;

vector <int> g[N];


int c[4][N];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
//    freopen("parts.in", "r", stdin);
//    freopen("parts.out", "w", stdout);
#endif




    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> c[0][i];
    }

    for(int i = 0; i < n; i++){
        cin >> c[1][i];
    }

    for(int i = 0; i < n; i++){
        cin >> c[2][i];
    }

    bool ok = 1;
    int u = 0;
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].pb(y);
        g[y].pb(x);
        if (g[x].size() > 2) ok = 0;
        if (g[y].size() > 2) ok = 0;
    }

    for(int i = 0; i < n; i++){
        if (g[i].size() == 1) u = i;
    }

    if (!ok){
        cout << -1;
        return 0;
    }


    vector <int> way;
    int pr = -1, go = 1;
    cerr << u << endl;
    while(go){
        go = 0;
        way.pb(u);
        for(int to : g[u]){
            if (to == pr) continue;
            pr = u;
            u = to;
            go = 1;
            break;
        }
    }
//    for(int to : way) cout << to << ' ';
//    return 0;
    vector <int> a(n, 0);
    vector <int> b(n, 0);
    int v1 = way[0];
    int v2 = way[1];
    reverse(way.begin(), way.end());
    way.pop_back();
    way.pop_back();
    reverse(way.begin(), way.end());
    int ans = 1e18;

//    return 0;

    for(int k = 0; k < 3; k++){
        for(int j = 0; j < 3; j++){
            if (k == j) continue;
            int cur = 0;
            cerr << k << ' ' << j << endl;
            cerr << v1 << ' ' << v2 << endl;
            a[v1] = k;
            a[v2] = j;
            cur += c[k][v1];
            cur += c[j][v2];
            int c1 = k;
            int c2 = j;
//            cerr << c1 << ' '
            for(int v : way){
                if ((c1 == 0 && c2 == 1) || (c1 == 1 && c2 == 0)){
                    a[v] = 2;
                    cur += c[2][v];
                    swap(c1, c2);

                    c2 = 2;
                    continue;
                }
                if ((c1 == 0 && c2 == 2) || (c1 == 2 && c2 == 0)){
                    a[v] = 1;
                    cur += c[1][v];
                    swap(c1, c2);
                    c2 = 1;
                    continue;
                }

                if ((c1 == 1 & c2 == 2) || (c1 == 2 & c2 == 1)){
                    a[v] = 0;
                    cur += c[0][v];
                    swap(c1, c2);
                    c2 = 0;
                    continue;
                }

            }

            if (ans > cur){
                ans = cur;
                b = a;
            }



        }
    }

    cout << ans << endl;
    for(int to : b) cout << to + 1 << ' ';







    return 0;
}
