#include <bits/stdc++.h>
using namespace std;
#define int long long

int GCD(int u, int v) {
    while (v != 0) {
        int r = u % v;
        u = v;
        v = r;
    }
    return u;
}

void solve()
{
    int a, b; cin >> a >> b;
    if(a < b) swap(a,b);

    if(GCD(a,b) == 1)
        cout << "finite\n";
    else
        cout << "infinite\n";
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    for(int i = 0; i < T; i++)
        solve();
}