#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int getans(int a, int b, int c) {
    int rtn = 0;
    for (int B = 0; B <= min(b, c / 2); B++) {
        int A = min(a, (b - B) / 2);
        rtn = max(rtn, 3 * A + 3 * B);
    }
    return rtn;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        printf("%d\n", getans(a, b, c));
    }
    return 0;
}
