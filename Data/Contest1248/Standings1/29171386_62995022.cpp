#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 1e5 + 10, MOD = 1e9 + 7;
int a[N];

void Main()
{
    int n, m, e1 = 0, e2 = 0, o1 = 0, o2 = 0; cin >> n;
    for (int i = 0; i < n; i ++) {
        int a; cin >> a;
        if (a % 2) o1++;
        else e1++;
    }
    cin >> m;
    for (int i = 0; i < m; i ++) {
        int a; cin >> a;
        if (a % 2) o2++;
        else e2++;
    }
    cout << e1 * e2 + o1 * o2 << "\n";
}

int32_t main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while (t--) {
        Main();
    }
}
