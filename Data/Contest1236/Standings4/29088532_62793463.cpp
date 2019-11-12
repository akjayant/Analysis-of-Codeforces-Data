#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define f first
#define s second

using namespace std;

const int N = 1e5 + 10;
const int md = 1e9 + 7;

int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j += 2) {
            cout << (j - 1) * n + i << ' ';
        }
        for (int j = 2; j <= n; j += 2) {
            cout << (j - 1) * n + (n - i + 1) << ' ';
        }
        cout << '\n';
    }
    return 0;
}
