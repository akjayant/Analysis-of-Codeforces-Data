#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define f first
#define s second

using namespace std;

const int N = 1e5 + 10;
const int md = 1e9 + 7;

int main() {
    int t, a, b, c;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &a, &b, &c);
        int x = min(c / 2, b);
        c -= x * 2;
        b -= x;
        int y = min(b / 2, a);
        cout << (x + y) * 3 << '\n';
    }
    return 0;
}
