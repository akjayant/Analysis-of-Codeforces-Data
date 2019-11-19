#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        
        int a = 0, b = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if(x & 1) b++;
            else a++;
        }
        int m;
        cin >> m;
        long long ans = 0;
        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            if(x & 1) 
                ans += b;
            else ans += a;
            
        }
        cout << ans << "\n";
    }
    return 0;
}
