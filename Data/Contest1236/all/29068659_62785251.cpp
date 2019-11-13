#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

int t, a, b, c;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &a, &b, &c);
        int ans = 0;
        ans = min(b, c/2);
        b -= ans;
        ans += min(a, b/2);
        ans *= 3;
        printf("%d\n", ans);
    }
    return 0;
}