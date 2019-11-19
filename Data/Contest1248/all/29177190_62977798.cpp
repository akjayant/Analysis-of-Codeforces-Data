#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int main()
{
    int n, m, x, T; scanf("%d", &T);
    while(T --)
    {
        int odd = 0, eve = 0; ll ans = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d", &x);
            if(x % 2 == 0) eve ++;
            else odd ++;
        }
        scanf("%d", &m);
        for(int i = 1; i <= m; i ++)
        {
            scanf("%d", &x);
            if(x % 2 == 0) ans += eve;
            else ans += odd;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
