#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        };
        sort(a.rbegin(), a.rend());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > i) {
                ans++;
            }
            else {
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}