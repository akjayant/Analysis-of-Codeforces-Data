#include<bits/stdc++.h>

#define LL long long
using namespace std;
//
// Created by 93569 on 2019/10/13.
//

long long n, K;
long long c[100005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> K;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(c, c + n);
    pair<pair<long long, long long>, int> L, R;
    for (int i = 0; i < n; i++) {
        if (c[i] != c[i + 1]) {
            L = make_pair(make_pair(c[i], i + 1), i);
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (c[i] != c[i - 1]) {
            R = make_pair(make_pair(c[i], n - i), i);
            break;
        }
    }
    while (K) {
        if (L.second >= R.second) break;
        if (K < L.first.second && K < R.first.second) break;
        if (L.first.second < R.first.second) {
            LLL:
            long long v = min(K / L.first.second, c[L.second + 1] - L.first.first);
            K -= L.first.second * v;
            v = L.first.first + v;
            for (int i = L.second; i <n; i++) {
                if (v != c[i + 1]) {
                    L = make_pair(make_pair(v, i + 1), i);
                    break;
                }
            }
        } else if (R.first.second < L.first.second) {
            RR:
            long long v = min(K / R.first.second, R.first.first - c[R.second - 1]);
            K -= R.first.second * v;
            v = R.first.first - v;
            for (int i = R.second; i >= 0; i--) {
                if (v != c[i - 1]) {
                    R = make_pair(make_pair(v, n - i), i);
                    break;
                }
            }
        } else {
            if (abs(L.first.first - c[L.second + 1]) * L.first.second >
                abs(R.first.first - c[R.second - 1]) * R.first.second) {
                goto LLL;
            } else {
                goto RR;
            }
        }
    }
    cout << max(R.first.first - L.first.first, 0LL) << endl;
    return 0;
}