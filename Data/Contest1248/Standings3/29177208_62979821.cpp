#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 10;
int t, n, m, a[N], b[N];
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        ll ao = 0, ae = 0, bo = 0, be = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%d", a + i);
            if(a[i] % 2)
                ao++;
            else
                ae++;
        }
        scanf("%d", &m);
        for(int i = 1; i <= m; i++) {
            scanf("%d", b + i);
            if(b[i] % 2)
                bo++;
            else
                be++;
        }
        ll ans = (ao * bo + ae * be);
        printf("%lld\n", ans);
    }
    return 0;
}
