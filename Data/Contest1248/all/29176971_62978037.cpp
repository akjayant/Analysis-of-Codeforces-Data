#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define F first
#define S second

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        ll a[] = {0, 0}, b[] = {0, 0};
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            a[t % 2]++;
        }
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            int t;
            cin >> t;
            b[t % 2]++;
        }
        cout << b[0] * a[0] + b[1] * a[1] << endl;
    }

    return 0;
}