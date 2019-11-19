#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, a, b, c, d, m;
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> d >> m;

        int ans1 = a / c;
        if(a % c) ans1++;

        int ans2 = b / d;
        if(b % d) ans2++;

        if(ans1 + ans2 > m) printf("-1\n");
        else printf("%d %d\n", ans1, ans2);

    }
    return 0;
}