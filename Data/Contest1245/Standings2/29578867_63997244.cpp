#include <bits/stdc++.h>
using namespace std;

int main() {
        ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
        long long test; cin >> test;
        while(test--) {
                long long a, b; cin >> a >> b;
                if(__gcd(a, b) == 1) {
                        cout << "Finite" << endl;
                } else  cout << "Infinite" << endl;
        }
}
