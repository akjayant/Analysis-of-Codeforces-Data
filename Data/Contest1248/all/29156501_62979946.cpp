#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, m, t, c1 = 0, c2 = 0, c3 = 0, c4 = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &t);
            if(t%2) ++c1;
            else ++c2;
        }
        scanf("%d", &m);
        for(int i = 0; i < m; ++i) {
            scanf("%d", &t);
            if(t%2) ++c3;
            else ++c4;
        }
        long long ans = 1LL*c1*c3 + 1LL*c2*c4;
        printf("%lld\n", ans);
    }
    return 0;
}