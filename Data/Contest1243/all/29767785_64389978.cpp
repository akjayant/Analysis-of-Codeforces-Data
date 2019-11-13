#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k;
    int n, t;
    
    cin >> k;
    while (k--) {
        cin >> n;
        
        vector<int> v;
        for (int i = 0; i < n; i++) {
            cin >> t;
            v.push_back(t);
        }
        
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (v[j] >= i) cnt++;
            }
            if (cnt >= i) ans = i;
        }
        
        cout << ans << endl;
    }
    
    return 0;
}
