#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int maxn = 1e5 + 5;
int a[maxn];
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    ll w = 0, h = 0;
    for (int i = 0, j = n / 2; i < n; ++i) {
        if (j) w += a[i], j--;
        else h += a[i];
    }
    cout << h * h + w * w << endl;
}
