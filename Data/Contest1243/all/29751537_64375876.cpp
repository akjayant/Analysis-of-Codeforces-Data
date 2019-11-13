#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int t;
int n;
int a[1005];

int main() {
#ifdef Yinku
    freopen("Yinku.in", "r", stdin);
#endif // Yinku
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        sort(a + 1, a + 1 + n, greater<int>());
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            if(a[i] >= i) {
                ans = i;
            } else {
                break;
            }
        }
        printf("%d\n", ans);
    }
}
