#include <cstdio>
using namespace std;
int T, n, m, p, q, num1, num2;
long long ans;
int main() {
    scanf("%d", &T);
    while(T--) {
        num1 = num2 = 0;
        ans = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &p);
            if(p % 2 == 0) num1++;
            else num2++;
        }
        scanf("%d", &m);
        for(int i = 1; i <= m; i++) {
            scanf("%d", &q);
            if(q % 2 == 0) ans += num1;
            else ans += num2;
        }
        printf("%lld\n", ans);
    }
    return 0;
}