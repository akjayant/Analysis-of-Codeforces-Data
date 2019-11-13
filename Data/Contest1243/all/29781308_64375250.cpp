#include<bits/stdc++.h>
using namespace std;
const int N = 1000 + 5;
typedef long long ll;
int k;
int n;
int a[N];
int cnt[N];
int main() {
    scanf("%d", &k);
    while(k--) {
        scanf("%d", &n);
        int x;
        memset(cnt, 0, sizeof(cnt));
        for(int i = 1; i <= n; i++) {
            scanf("%d", &x);
            cnt[x]++;
        }
        for(int i = 1000; i >= 1; i--) {
            cnt[i] = cnt[i + 1] + cnt[i];
        }
        int ans = 1;
        for(int i = 1; i <= 1000; i++) {
            if(cnt[i] >= i) {
                ans = max(ans, i);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
