#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1.0)
#define ll long long
const int N = 3005;

char s[N];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("c.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d %s", &n, s);
        int cnt = 0, mi = n + 1, mx = -1;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                mi = min(mi, i);
                mx = max(mx, i);
                cnt++;
            }
        }
        if(cnt == 0) printf("%d\n", n);
        else {
            int v1 = max(n - mi, mx + 1) * 2;
            int v2 = n + cnt;
            printf("%d\n", max(v1, v2));
        }
    }
    return 0;
}

