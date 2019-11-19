#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("in.inp", "r", stdin);
	//freopen("out.out", "w", stdout);
	int n, l, r, L, R;
    long long k, cur;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    l = r = 1;
    L = a[0];
    R = a[n - 1];
    if (L == R)
    {
        cout << 0;
        return 0;
    }
    while (a[l] == L) ++l;
    while (a[n - r - 1] == R) ++r;
    while (k >= min(l, r))
    {
        if (l < r)
        {
            cur = min(k / l, (long long) a[l] - L);
            k -= cur * l;
            L += cur;
            while (a[l] == L) ++l;
        }
        else
        {
            cur = min(k / r, (long long) R - a[n - r - 1]);
            k -= cur * r;
            R -= cur;
            while (a[n - r - 1] == R) ++r;
        }
        if (L == R)
        {
            cout << 0;
            return 0;
        }
    }
    cout << R - L;
    return 0;
}
