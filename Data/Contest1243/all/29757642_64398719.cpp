#include <bits/stdc++.h>

#define y1 theboatman
#define make_struct(args...) {args}

using namespace std;
typedef long long ll;

const int N = 1e6 + 10;
const int inf = 1e9 + 10;
const long long INF = 1e18 + 10;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll n;
    cin >> n;

    for(ll del = 2; del * del <= n; del++) {
        if (n % del == 0) {
            while(n % del == 0) {
                n /= del;
            }

            if (n == 1) {
                cout << del << "\n";
            }
            else {
                cout << "1\n";
            }
            return 0;
        }
    }

    cout << n << "\n";
    return 0;
}
/*
*/
