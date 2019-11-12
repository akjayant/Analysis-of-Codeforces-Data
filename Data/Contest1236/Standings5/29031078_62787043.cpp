#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define pll pair <ll, ll>
using namespace std;

int T;
int a, b, c;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> a >> b >> c;
        int p = min(a, b / 2) * 3;
        int p2 = min(b - (p / 3) * 2, c / 2) * 3;
        int d = min(b, c / 2) * 3;
        int d2 = min(a, (b - d / 3) / 2) * 3;
        cout << max(p + p2, d + d2) << '\n';
    }
}
