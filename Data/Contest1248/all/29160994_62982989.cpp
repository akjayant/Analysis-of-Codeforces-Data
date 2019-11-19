#include <bits/stdc++.h>

//#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3", "Ofast", "unroll-loops", "fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")


#define int long long
#define endl '\n'

using namespace std;

signed main (){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int i, n;
    cin >> n;
    vector < int > a(n);
    int s = 0;
    for (i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
    }
    sort(a.begin(), a.end());
    int x = 0;
    for (i = 0; i < n / 2; i++){
        x += a[i];
    }
    cout << x * x + (s - x) * (s - x) << endl;

    return 0;
}

