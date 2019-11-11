#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1e6+10;
int T, a, b;

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &a, &b);
        if(__gcd(a, b) == 1) puts("Finite");
        else puts("Infinite");
    }

    return 0;
}