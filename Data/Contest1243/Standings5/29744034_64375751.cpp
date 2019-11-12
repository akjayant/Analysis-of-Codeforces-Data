#include <bits/stdc++.h>
#define INF 1e18
#define M 1000000007
#define ll long long
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[100005];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int ans = -1;
        sort(a, a + n, cmp);
        for(int i = 0; i < n; i++)
        {
            if(a[i] < i + 1)
            {
                ans = i;
                break;
            }
        }
        if(ans == -1) ans = n;
        cout << ans << endl;
    }
}