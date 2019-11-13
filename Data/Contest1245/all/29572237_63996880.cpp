#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int N = 100005;

int main() {
    int _;
    cin >> _;
    while (_--) {
        int a, b;
        cin >> a >> b;
        puts(__gcd(a, b) == 1 ? "Finite" : "Infinite");
    }
    return 0;
}
