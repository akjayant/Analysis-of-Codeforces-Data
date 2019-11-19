#include <bits/stdc++.h>

//#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3", "Ofast", "unroll-loops", "fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")


//#define int long long
#define endl '\n'

using namespace std;

signed main (){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int j, t;
    cin >> t;
    for (j = 0; j < t; j++){
        int n, m, i;
        int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
        cin >> n;
        for (i = 0; i < n; i++){
            int x; cin >> x;
            c1 += int(x % 2 == 0);
            c2 += int(x % 2 == 1);
        }
        cin >> m;
        for (i = 0; i < m; i++){
            int x; cin >> x;
            c3 += int(x % 2 == 0);
            c4 += int(x % 2 == 1);
        }
        cout << (long long)c1 * c3 + (long long)c2 * c4 << endl;
    }
    return 0;
}

