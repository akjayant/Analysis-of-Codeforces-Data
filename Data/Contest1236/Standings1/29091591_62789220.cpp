#include<bits/stdc++.h>
#define F first
#define S second
#define ll long long
#define pb push_back
using namespace std;

signed main() {
    int t;
    int a, b, c;
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        int ans = 0;
        for(int k = 0 ; k <= a && k * 2 <= b ; k++) {
            int bb = b - k * 2;
            ans = max(ans, k + min(bb, c / 2));
        }
        cout << ans * 3<< '\n';

    }
    return 0;
}