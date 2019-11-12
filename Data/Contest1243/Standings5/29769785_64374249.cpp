#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, i;

    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> a(n);
        for(i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        for(i = 0; i < n; i++) {
            if(a[i] >= n-i) {
                cout << n-i << endl;
                break;
            }
        }
    }

    return 0;
}
