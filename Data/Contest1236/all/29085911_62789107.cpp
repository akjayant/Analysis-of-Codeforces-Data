#include <cstdio>
#include <algorithm>
#include <iostream>

int main() {
    
    int t; scanf("%d", &t);
    
    while (t --) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);

        int ans = 0; 

        for (int i = 0; i <= a; i ++) 
            for (int j = 0; j <= b - 2 * i; j ++) 
                if (2 * j <= c) ans = std::max(ans, (i + j) * 3); 

        printf("%d\n", ans);
    }

    return 0;
}