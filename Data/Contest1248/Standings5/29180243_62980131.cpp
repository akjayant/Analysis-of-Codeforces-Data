#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int p[N], q[N];
int main()
{
    int t;
    cin >>t;
    while (t --){
        int n, m;
        cin >> n;
        int y;
        ll num1 = 0, num2 = 0;
        for (int i = 1; i <= n; ++ i){
            scanf ("%d", &p[i]);
            if (p[i] & 1) num1 ++;
        }
        cin >> m;
        int x;
        for (int i = 1; i <= m; ++ i){
            scanf("%d", &q[i]);
            if (q[i] & 1) num2 ++;
        }
        ll ans = 1ll * num1 * num2 + 1ll * (n - num1) * (m - num2);
        printf("%I64d\n", ans);
    }
    return 0;
}

