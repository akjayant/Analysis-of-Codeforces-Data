#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define f first
#define s second

const int MAXN = 1e6 + 3;

int main() {
    int z;
    int a, b, c, d, k;
    int x, y;
    scanf("%d", &z);
    while (z--) {
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
        x = a / c;
        if (a % c != 0)
            x++;
        y = b / d;
        if (b % d != 0)
            y++;
        if (x + y <= k)
            printf("%d %d\n", x, y);
        else
            printf("-1\n");
    }
    return 0;
}

