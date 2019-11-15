#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
const int N = 1e2 + 10;
const int mod = 1e9 + 7;

int t;
int n;
int a, b, c;
vector < char > ans;
char e[N];
int cnt;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for (int o = 1; o <= t; ++o)
    {
        cin >> n;
        cin >> a >> b >> c;
        int r = 0, p = 0, s = 0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> e[i];
            if (e[i] == 'R') ++r;
            else if (e[i] == 'P') ++p;
            else ++s;
        }
        cnt = 0;
        int a1 = 0, b1 = 0, c1 = 0;
        if (a > s) a1 = a - s;
        if (b > r) b1 = b - r;
        if (c > p) c1 = c - p;
        ans.clear();
        for (int i = 1; i <= n; ++i)
        {
            if (e[i] == 'R')
            {
                if (b != 0)
                {
                    ++cnt;
                    --b;
                    ans.push_back('P');
                } else if (a1 != 0)
                {
                    --a1;
                    ans.push_back('R');
                } else if (c1 != 0)
                {
                    --c1;
                    ans.push_back('S');
                }
            } else if (e[i] == 'P')
            {
                if (c != 0)
                {
                    ++cnt;
                    --c;
                    ans.push_back('S');
                } else if (b1 != 0)
                {
                    --b1;
                    ans.push_back('P');
                } else if (a1 != 0)
                {
                    --a1;
                    ans.push_back('R');
                }
            } else
            {
                if (a != 0)
                {
                    ++cnt;
                    --a;
                    ans.push_back('R');
                } else if (c1 != 0)
                {
                    --c1;
                    ans.push_back('S');
                } else if (b1 != 0)
                {
                    --b1;
                    ans.push_back('P');
                }
            }
        }
        if (cnt >= n / 2 + n % 2)
        {
            cout << "YES\n";
            for (auto t1 : ans) cout << t1;
            cout <<"\n";
        } else cout << "NO\n";
    }

    return 0;
}
