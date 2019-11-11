#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define inc(i, l, r) for (int i = l; i <= r; i++)
#define dec(i, l, r) for (int i = l; i >= r; i--)
#define mes(x, k) memset(x, k, sizeof(x))
#define bug() printf("LINE: %d.\n", __LINE__)
const int maxn = 1e6 + 5;

int t, a, b;

int main() {
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (__gcd(a, b) == 1)
            puts("Finite");
        else
            puts("Infinite");
    }
}
