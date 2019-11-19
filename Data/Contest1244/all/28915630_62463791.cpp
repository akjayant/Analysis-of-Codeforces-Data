#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define dbg(x) cerr << #x << " = " << x << endl
#define _ << ' ' <<
using namespace std;
using ll = long long;
using vi = vector<int>;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int x = a / c + (a % c != 0);
        int y = b / d + (b % d != 0);
        if (x + y > k)
            cout << -1;
        else
            cout << x _ y;
        cout << '\n';
    }
}
