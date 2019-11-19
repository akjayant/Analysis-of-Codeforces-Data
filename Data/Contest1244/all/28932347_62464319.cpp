#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int a, b, c, d, k;

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
        int min_a = a % c == 0 ? a / c : a / c + 1;
        int min_b = b % d == 0 ? b / d : b / d + 1;
        if (min_a + min_b > k) {
            printf("%d\n", -1);
        } else {
            printf("%d %d\n", min_a, min_b);
        }
    }
    return 0;
}
