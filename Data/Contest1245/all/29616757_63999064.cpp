#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}
void solve() {
    int x, y;
    cin >> x >> y;
    if(gcd(x, y) == 1)
        cout << "Finite" << endl;
    else
        cout << "Infinite" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for(auto i = 0; i < t; ++i)
        solve();
}