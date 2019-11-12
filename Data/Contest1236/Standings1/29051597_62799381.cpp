#include <bits/stdc++.h>
#define N ((int)3003)
#define MD ((int)1e9+7)

using namespace std;

int a[N][N];

int main() {
    int n;
    cin >> n;
    long long k = n * n;
    for (int j = 1; j <= n; j++) {
        if (j % 2)
            for (int i = 1; i <= n; i++) {
                a[i][j] = k--;
            } else
            for (int i = n; i >= 1; i--) {
                a[i][j] = k--;
            }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j];
            if (j == n)
                cout << endl;
            else
                cout << " ";
        }

    }

    return 0;
}
