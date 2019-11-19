


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int a, b, c, d, n, T;

int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &n);
        int ans_a = (a - 1) / c + 1, ans_b = (b - 1) / d + 1;
        if (ans_a + ans_b <= n)
            printf("%d %d\n", ans_a, ans_b);
        else
            puts("-1");
    }
    
    return 0;
}
