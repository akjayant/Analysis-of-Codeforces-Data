#include <bits/stdc++.h>

#define maxn 200005
#define mod 1000000007
#define inf 0x3f3f3f3f
#define start ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
int a[305][305];

int main() {
    start;
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (i & 1) {
            int st = (i - 1) * n;
            for (int j = 1; j <= n; ++j)
                a[j][i] = ++st;
        } else {
            int st = i * n;
            for (int j = 1; j <= n; ++j)
                a[j][i] = st--;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}