#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1010;
int a[maxn];
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 0;i < n;i++)
            scanf("%d", a+i);
        sort(a, a+n);
        int ans = 1;
        for(int i = n-1;i >= 0;i--)
        {
            if(n-i > a[i]) break;
            ans = n-i;
        }
        printf("%d\n", ans);
    }
    return 0;
}