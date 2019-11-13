#include <bits/stdc++.h>

using namespace std;

int n, r, p, s, R, P, S;
string a;

void solve()
{
    cin >> n >> r >> p >> s >> a;
    R = P = S = 0;
    for (int i = 0; i < n; ++i)
    {
        R += a[i] == 'R';
        P += a[i] == 'P';
        S += a[i] == 'S';
    }
    if ((min(r, S) + min(p, R) + min(s, P)) << 1 < n)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 'R' && p)
        {
            a[i] = 'p';
            --p;
        }
        if (a[i] == 'P' && s)
        {
            a[i] = 's';
            --s;
        }
        if (a[i] == 'S' && r)
        {
            a[i] = 'r';
            --r;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 'r')
        {
            a[i] = 'R';
            continue;
        }
        if (a[i] == 'p')
        {
            a[i] = 'P';
            continue;
        }
        if (a[i] == 's')
        {
            a[i] = 'S';
            continue;
        }
        if (r)
        {
            a[i] = 'R';
            --r;
            continue;
        }
        if (p)
        {
            a[i] = 'P';
            --p;
            continue;
        }
        a[i] = 'S';
        --s;
    }
    cout << a << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
