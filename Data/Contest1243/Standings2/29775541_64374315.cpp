#include<bits/stdc++.h>
using namespace std;

const int N = 1000 + 10;
int a[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        int ans = 1;
        for (int i = n - 2; ~i; i--)
            ans = max(ans, min(a[i], n - i));
        cout << ans << "\n";
    }
    return 0;
}