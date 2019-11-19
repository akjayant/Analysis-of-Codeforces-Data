#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define mod 1000000007

int main() {
    int n, m;
    cin >> m >> n;
    ll cnt[2][2], temp[2][2];
    ll c1, c2;
    if (n > 1) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cnt[i][j] = 1;
            }
        }
        for (int i = 2; i < n; i++) {
            temp[0][1] = cnt[0][0];
            temp[1][1] = cnt[0][1];
            temp[1][0] = cnt[0][1];
            temp[1][0] += cnt[1][1];
            if (temp[1][0] > mod) temp[1][0] -= mod;
            temp[0][0] = cnt[1][0];
            temp[0][1] += cnt[1][0];
            if (temp[0][1] > mod) temp[0][1] -= mod;

            for (int k = 0; k < 2; k++) {
                for (int j = 0; j < 2; j++) {
                    cnt[k][j] = temp[k][j];
                }
            }
        }
        c2 = mod - 2;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c2 += cnt[i][j];
                if (c2 > mod) c2 -= mod;
            }
        }
    } else {
        c2 = 0;
    }
    if (m > 1) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cnt[i][j] = 1;
            }
        }
        for (int i = 2; i < m; i++) {
            temp[0][1] = cnt[0][0];
            temp[1][1] = cnt[0][1];
            temp[1][0] = cnt[0][1];
            temp[1][0] += cnt[1][1];
            if (temp[1][0] > mod) temp[1][0] -= mod;
            temp[0][0] = cnt[1][0];
            temp[0][1] += cnt[1][0];
            if (temp[0][1] > mod) temp[0][1] -= mod;

            for (int k = 0; k < 2; k++) {
                for (int j = 0; j < 2; j++) {
                    cnt[k][j] = temp[k][j];
                }
            }
        }
        c1 = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c1 += cnt[i][j];
                if (c1 > mod) c1 -= mod;
            }
        }
    } else {
        c1 = 2;
    }
    cout << (c1 + c2) % mod << "\n";
    return 0;
}