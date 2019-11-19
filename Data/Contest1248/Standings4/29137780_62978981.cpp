// Created by sz
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
#ifdef LOCAL
    freopen("./input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        int odd1 = 0, even1 = 0;
        for (int i = 0; i < n; i++){
            cin >> p[i];
            if(p[i]&1) odd1++;
            else even1++;
        }
        int m;
        cin >> m;
        vector<int> q(m);
        int odd2 = 0, even2 = 0;
        for (int i = 0; i < m; i++){
            cin >> q[i];
            if(q[i]&1)odd2++;
            else even2++;
        }
        ll ans = (ll) odd1 * odd2 + (ll) even1 * even2;
        cout << ans << "\n";
        
    }
    
    return 0;
}
