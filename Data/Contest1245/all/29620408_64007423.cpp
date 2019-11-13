#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e5 + 5;
const int M = 500;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(__gcd(a, b) == 1) printf("Finite\n");
        else printf("Infinite\n");
    }
}

/**
564
1 1 5
1 500 4
2 499 1
*/
