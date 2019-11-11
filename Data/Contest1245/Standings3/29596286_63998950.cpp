#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define dbg(x) cerr << #x << " = " << x << endl
#define _ << ' ' <<
using namespace std;
using ll = long long;
using vi = vector<int>;

string A = "RPS";
string B = "PSR";

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a, b, c;
        cin >> a >> b >> c;
        string s, z(n, ' ');
        cin >> s;
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == 'R')
            {
                if (b > 0)
                {
                    cnt++, b--;
                    z[i] = 'P';
                }
            }
            if (s[i] == 'P')
            {
                if (c > 0)
                {
                    cnt++, c--;
                    z[i] = 'S';
                }
            }
            if (s[i] == 'S')
            {
                if (a > 0)
                {
                    cnt++, a--;
                    z[i] = 'R';
                }
            }
        }
        if (cnt < n / 2 + n % 2)
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            for (int i = 0; i < n; ++i)
            {
                if (z[i] == ' ')
                {
                    if (a)
                        z[i] = 'R', a--;
                    else if (b)
                        z[i] = 'P', b--;
                    else if (c)
                        z[i] = 'S', c--;
                }
            }
            cout << z << '\n';
        }
    }
}
