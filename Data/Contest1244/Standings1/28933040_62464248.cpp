#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for(int s = 0; s < t; s++){
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int x = (a + c - 1) / c, y = (b + d - 1) / d;
        if(x + y <= k)
            cout << x << " " << y << "\n";
        else
            cout << -1 << "\n";
    }
    return 0;
}
