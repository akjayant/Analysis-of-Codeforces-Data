#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 10;
int n, a[N];
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        scanf("%d", a + i);
    sort(a + 1, a + n + 1);
    if(n % 2 == 0) {
        int z = n / 2;
        ll c = 0, k = 0;
        for(int i = 1; i <= n / 2; i++)
            c += a[i];
        for(int i = n / 2 + 1; i <= n; i++)
            k += a[i];
        ll ans = c * c + k * k;
        cout << ans << endl;
    } else {
        int z = n / 2;
        ll c = 0, k = 0;
        for(int i = 1; i <= z; i++)
            c += a[i];
        for(int i = n / 2 + 1; i <= n; i++)
            k += a[i];
        ll ans = c * c + k * k;
        cout << ans << endl;
    }
    return 0;
}
