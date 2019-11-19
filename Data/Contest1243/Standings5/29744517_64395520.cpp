#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5 + 112;
const int M = 19;
const int MOD = 1e9 + 7;

signed main () {
    int n;
    cin >> n;
    set <int> st;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            st.insert(i);
            while (n % i == 0) n /= i;
            if (n == 1) {
                return cout << i, 0;
            }
            else {
                return cout << 1, 0;
            }
        }
    }
    cout << n;

}
