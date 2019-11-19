#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;
int a[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, greater<int>());
    ll x = 0, y = 0;
    for (int i = 0; i <= (n - 1) / 2; i++)
        x += a[i];
    for (int i = (n - 1) / 2 + 1; i < n; i++)
        y += a[i];
    cout << x * x + y * y << "\n";
    return 0;
}