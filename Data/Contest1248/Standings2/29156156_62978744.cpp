//in the name of holy satan
#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

class Test
{
public:
    lint num[2][2];
    void init()
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
                num[i][j] = 0;
        }
    }
    Test()
    {
        init();
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int a;

            cin >> a;
            num[a % 2][0]++;
        }
        int m;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            int a;
            cin >> a;
            num[a % 2][1]++;
        }
        lint ans = 0;
        ans = num[0][0] * num[0][1] + num[1][1] * num[1][0];
        cout << ans << '\n';
    }
};

int main()
{
    iostream::sync_with_stdio(false);
    int q;
    cin >> q;
    while (q)
    {
        auto p = new Test();
        delete p;
        q--;
    }
}