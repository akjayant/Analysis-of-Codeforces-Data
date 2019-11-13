#include <bits/stdc++.h>

using namespace std;
int a[1001];
int main()
{
    int k;
    cin >> k;
    while(k --)
    {
        int n , ans = 0;
        cin >> n;
        for(int i = 1; i <= n; i ++)
        {
            cin >> a[i];
        }
        sort(a + 1 , a + n + 1);
        for(int i = 1; i <= n; i ++)
        {
                ans = max(ans , min(a[i] , n - i + 1));

        }
        cout << ans << endl;
    }
    return 0;
}
