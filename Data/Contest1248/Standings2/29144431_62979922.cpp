#include <cstdio>

int main() {
    long long evenp, evenq, oddp, oddq;
    int t;
    scanf("%d", &t);
    while(t--) {
        evenp = evenq = oddp = oddq = 0;
        int n, m, x;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &x);
            if(x & 1) {
                oddp++;
            }
            else {
                evenp++;
            }
        }
        scanf("%d", &m);
        for(int i = 1; i <= m; i++) {
            scanf("%d", &x);
            if(x & 1) {
                oddq++;
            }
            else {
                evenq++;
            }
        }
        printf("%lld\n", evenq * evenp + oddq * oddp);
    }
    return 0;
}