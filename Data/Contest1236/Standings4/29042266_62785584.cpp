#include <bits/stdc++.h>

using namespace std;

int t, a, b, c;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &a, &b, &c);
        int rest1 = b - min(a, b / 2) * 2, rest2 = b - min(b, c / 2);
        printf("%d\n", max(min(a, b / 2) * 3 + min(rest1, c / 2) * 3, min(b, c / 2) * 3 + min(rest2 / 2, a) * 3));
    }
}
