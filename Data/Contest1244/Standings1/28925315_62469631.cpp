


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int T, n;

int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        int pos_l = n, pos_r = -1;
        for (int k = 0; k < n; ++ k) {
            char c = getchar();
            while (c < '0' || c > '1') c = getchar();
            if (c == '1') {
                pos_l = min(pos_l, k);
                pos_r = max(pos_r, k);
            }
        }
        if (pos_l <= pos_r)
            printf("%d\n", max(n - pos_l, pos_r + 1) * 2);
        else
            printf("%d\n", n);
    }
    
    return 0;
}
