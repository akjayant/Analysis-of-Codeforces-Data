#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
char s[1010];

int main(){
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        scanf("%s", s);
        int mn = INT_MAX;
        int mx = INT_MIN;
        int ans = n;
        for (int i = 0 ; s[i]; ++i)
            if (s[i] == '1')
            {
                mn = i;
                break;
            }
        for (int i = 0 ; s[i]; ++i)
            if (s[i] == '1')
            {
                mx = i;
            }
        if (mx != INT_MIN)
            ans = max(ans, mx+mx+2);
        if (mn != INT_MAX)
            ans = max(ans, (n-mn) * 2);
        printf("%d\n", ans);
    }

	return 0;
}
