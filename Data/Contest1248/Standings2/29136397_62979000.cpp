#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N], b[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cin >> m;
        for (int i = 0; i < m; i++)
            cin >> b[i];
        int cnt1[] = {0, 0}, cnt2[] = {0, 0};
        for (int i = 0; i < n; i++)
            cnt1[a[i] % 2]++;
        for (int i = 0; i < m; i++)
            cnt2[b[i] % 2]++;
        cout << 1LL * cnt1[0] * cnt2[0] + 1LL * cnt1[1] * cnt2[1] << "\n";
    }
    return 0;
}