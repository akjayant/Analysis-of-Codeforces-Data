#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int y = min(c/2, b);
        b -= y;
        int ans = 3*y;
        ans += 3*min(b/2, a);
        printf("%d\n", ans);
    }
    return 0;
}
