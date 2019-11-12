#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>
using namespace std;

long long gcd(long long big, long long small) {
    if (big % small == 0) return small;
    else return gcd (small, big % small);
}

int main(int argc, const char * argv[]) {
    int k, n;
    cin >> k;
    for (int j = 0; j < k; ++j) {
        cin >> n;
        vector<int>a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int ans = 0;
        int t, u = 0;
        for (int i = n - 1; i >= 0; --i) {
            ++u;
            t = min(u, a[i]);
            if (ans < t) ans = u;
        }
        cout << ans << endl;
    }
    return 0;
}
