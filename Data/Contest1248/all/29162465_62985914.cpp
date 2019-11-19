#include <bits/stdc++.h>

using namespace std;

int v[100010];
int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v, v + n);

    long long x = 0, y = 0;
    for (int i = 0; i < n / 2; ++i)
        x += v[i];

    for (int i = n / 2; i < n; ++i)
        y += v[i];

    cout << x * x + y * y << "\n";
    return 0;
}
