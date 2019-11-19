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
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool h = false;
        for (char c : s)
            if (c == '1')
                h = true;

        if (!h)
        {
            cout << n;
        }
        else
        {
            int a = s.find('1');
            int b = s.rfind('1');
            int c = max(n - a, b + 1);
            cout << 2 * c;
        }
        cout << '\n';
    }
}
