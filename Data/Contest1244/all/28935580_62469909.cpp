#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000 + 10;
char s[maxn];

int main()
{
    int _;
    scanf("%d", &_);
    while(_ --)
    {
        int n;
        scanf("%d", &n);
        scanf("%s", s + 1);
        int l = 0, r = 0;
        for(int i = 1; i <= n; i ++) if(s[i] == '1')
        {
            if(l == 0) l = i;
            r = i;
        }
        if(l == 0)
        {
            printf("%d\n", n);
            continue;
        }
        int res = max(2 * r, 2 * (n - l + 1));
        res = max(res, n + 1);
        printf("%d\n", res);
    }
    return 0;
}
