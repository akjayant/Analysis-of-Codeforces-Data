#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 10;
const int mod  = 1e9 + 7;
#define pb    push_back
#define mp    make_pair
int n, m;
int a[maxn];
bool check(int x)
{
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        if (a[i] >= x)
            ans++;
    }
    return ans >= x;
}
int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    while (n--)
    {
        cin >> m;
        for (int i = 0; i < m; i++)
            cin >> a[i];
        int r = 0, l = m, mid;
        while (r <= l)
        {
            mid = (r + l) / 2;
            if (check(mid))
                r = mid + 1;
            else
                l = mid - 1;
        }
        cout << l << endl;
    }
    return 0;
}
