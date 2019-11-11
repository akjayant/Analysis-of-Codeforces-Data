#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define pll pair<ll, ll>

int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << (gcd(a, b) == 1 ? "Finite\n" : "Infinite\n");
    }


    return 0;
}