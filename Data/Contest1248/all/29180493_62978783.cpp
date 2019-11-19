#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 100033;

int n, m;
ll a[2], b[2];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        for (int i = 1; i <= n; i++)
        {
            int temp;
            cin >> temp;
            a[temp & 1]++;
        }
        cin >> m;
        for (int i = 1; i <= m; i++)
        {
            int temp;
            cin >> temp;
            b[temp & 1]++;
        }
        cout << a[0] * b[0] + a[1] * b[1] << endl;
    }
 //   system("pause");
    return 0;
}