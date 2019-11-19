#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define F first
#define S second

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

int main() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    ll x = 0, y = 0;
    for (int i = 0; i < n / 2; i++)
        y += a[i];
    for (int i = n / 2; i < n; i++)
        x += a[i];
    cout << x * x + y * y << endl;

    return 0;
}