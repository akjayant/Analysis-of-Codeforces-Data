#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<pair<long long, long long> > ans;
    long long n, n1;
    cin >> n;
    n1 = n;
    for (int i = 2; i <= round(sqrt(n)); i++) {
        if (n1 % i == 0) {
            int cnt = 0;
            while (n1 % i == 0) {
                cnt++;
                n1 /= i;
            }
            ans.push_back({i, cnt});
        }
    }
    if (n1 != 1) {
        int f = 0;
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i].first == n1) {
                ans[i].second++;
                f = 1;
                break;
            }
        }
        if (f == 0) {
            ans.push_back({n1, 1});
        }
    }
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (ans.size() != 1) {
        cout << 1 << endl;
        return 0;
    }
    if (ans[0].second == 1) {
        cout << n << endl;
    } else {
        cout << ans[0].first << endl;
    }
}

