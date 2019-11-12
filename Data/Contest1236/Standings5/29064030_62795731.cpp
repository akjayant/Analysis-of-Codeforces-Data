#include <bits/stdc++.h>

#define fr first
#define sc second
#define mk make_pair

using namespace std;

int mod = 1e9 + 7;

long long binpow(long long a, long long b) {
    if (b == 0) {
        return 1;
    }
    if (b % 2 == 1) {
        return (a * binpow(a, b - 1)) % mod;
    } else {
        long long h = binpow(a, b / 2);
        return (h * h) % mod;
    }
}

int ar[1000][1000];

int main() {
    int n, cnt = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            for (int j = 1; j <= n; j++) {
                ar[i][j] = cnt++;
            }
        } else {
            for (int j = n; j >= 1; j--) {
                ar[i][j] = cnt++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ar[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}
