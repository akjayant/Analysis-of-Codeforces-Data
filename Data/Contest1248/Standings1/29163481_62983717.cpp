#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[100005];
int main() {
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sort(a + 1, a + 1 + n);
    ll ans = 0;
    ll x = 0, y = 0;
    for(int i = 1; i <= n / 2; i++) y += a[i];
    for(int i = n / 2 + 1; i <= n; i++) x += a[i];
    ans = x * x + y * y;
    cout << ans << endl;
    return 0;
}
