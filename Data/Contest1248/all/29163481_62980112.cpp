#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[100005];
int b[100005];
int main() {
    int T;
    cin>>T;
    while(T--) {
        int n, m;
        cin>>n;
        int ji1 = 0, ji2 = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if(a[i] & 1) ji1++;
        }
        cin>>m;
        for(int i = 1; i <= m; i++) {
            scanf("%d", &b[i]);
            if(b[i] & 1) ji2++;
        }
        ll ans = 1LL * ji1 * ji2 + 1LL * (n - ji1) * (m - ji2);
        cout << ans << endl;
    }

    return 0;
}
