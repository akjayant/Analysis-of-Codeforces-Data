#include <bits/stdc++.h>
using namespace std;
char s[500000];
int a[500000];
int n;

int judge()
{
    int sum = 0, minn = n;
    for(int i = 1; i <= n; i ++)
    {
        a[i] = a[i - 1] + (s[i]=='('?1:-1);
        minn = min(minn, a[i]);
    }
    if(a[n] != 0) return 0;
    for(int i = 1; i < n; i ++)
    {
        int putch = a[n] - a[n - i];
        if(minn + putch >= 0) sum ++;
    }
    if(minn >= 0) sum ++;
    return sum;
}

int main()
{
    int ans = -1, l = 0, r = 0; a[0] = 0;
    scanf("%d%s", &n, s + 1);
    for(int i = 1; i <= n; i ++)
        for(int j = i; j <= n; j ++)
        {
            swap(s[i], s[j]);
            int tmp = judge();
            if(tmp > ans) ans = tmp, l = i, r = j;
            swap(s[i], s[j]);
        }
    cout << ans << endl;
    cout << l << " " << r;
    return 0;
}
