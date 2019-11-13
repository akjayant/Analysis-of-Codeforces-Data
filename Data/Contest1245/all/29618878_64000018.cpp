#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


const int MAXN = 2e5;
int d[MAXN];

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
int main() {
//     freopen("negcycle.in", "r", stdin);
//     freopen("negcycle.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        if (gcd(a, b) > 1) {
            cout << "Infinite" << endl;
        } else {
            cout << "Finite" << endl;
        }
    }
}
