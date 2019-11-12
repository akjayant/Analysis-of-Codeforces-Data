#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int a[1005];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        int ans = -0x3f3f3f3f;
        for(int i = 1; i <= n ; ++i) {
            int cnt = 0;
            for(int j = 0; j < n; ++j)
                if(a[j] >= i) ++cnt;
            ans = max(ans, min(i, cnt));
        }
        printf("%d\n", ans);
    }
    return 0;
}