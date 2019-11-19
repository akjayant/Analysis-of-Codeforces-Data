#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <set>
using namespace std;
int main(int argc,char **argv)
{
    int t, m, n;
    cin >> t;
    while(t--)
    {
        long long odd1 = 0, even1 = 0, odd2 = 0, even2 = 0, x;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld", &x);
            if(x%2) odd1++;
            else even1++;
        }
        cin >> m;
        for(int i = 1; i <= m; i++)
        {
            scanf("%lld", &x);
            if(x%2) odd2++;
            else even2++;
        }
        long long ans = 0;
        ans = odd1*odd2 + even1*even2;
        printf("%lld\n", ans);
    }
    return 0;
}
