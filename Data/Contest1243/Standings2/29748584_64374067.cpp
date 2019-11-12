#include <bits/stdc++.h>
using namespace std;

int a[1010];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        for(int i=1; i<=n; i++)
            scanf("%d", &a[i]);
        sort(a+1, a+n+1);
        int ans = 1;
        for(int i=n; i>=1; i--) {
            if(a[i]<n-i+1)
                break;
            ans = n-i+1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
