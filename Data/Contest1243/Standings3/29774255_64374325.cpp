#include <bits/stdc++.h>

using namespace std;

int main() {
    int k;
    cin >> k;
    for (int e = 0; e < k; e++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, min(a[i], n - i));
        }
        cout << ans << "\n";
    }


    return 0;
}

