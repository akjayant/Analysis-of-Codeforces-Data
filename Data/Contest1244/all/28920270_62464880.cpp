#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define ll long long
#define f first
#define s second
using namespace std;


int main() {
    int t;
    cin >> t;
    for(int q = 0; q < t; q++) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        if((a + c - 1) / c + (b + d - 1) / d > k) cout << -1;
        else cout << (a + c - 1) / c << " " << (b + d - 1) / d;
        cout << "\n";
    }
    return 0;
}