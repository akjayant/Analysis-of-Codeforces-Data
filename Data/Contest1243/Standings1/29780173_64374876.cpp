#include <bits/stdc++.h>
#define inf 1000000000
using namespace std;
typedef long long ll;

int n, t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--){
        int n, a[1005];
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        int mx = 0;
        for (int i = n - 1, c = 1; i >= 0; i--, c++){
            if (c <= a[i])
                mx = c;
        }
        for (int i = n - 1, c = 1; i >= 0; i--, c++){
            if (a[i] <= c) {
                cout << max(mx, a[i]) << "\n";
                break;
            }
        }
    }
}
