#include <bits/stdc++.h>

#pragma GCC optimize("O3")

#define f first
#define s second
#define p push
#define pb push_back
#define ll long long
#define ld long double

using namespace std;

const int N = 2e5 + 2, inf = 1e9 + 10;

int a[N];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q;
    cin >> q;
    for(int t = 0; t < q; ++t){
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int r = (a + c - 1) / c;
        int ka = (b + d - 1) / d;
        if(r + ka <= k){
            cout << r << " " << ka << "\n";
        }else
            cout << -1 << "\n";
    }

}
