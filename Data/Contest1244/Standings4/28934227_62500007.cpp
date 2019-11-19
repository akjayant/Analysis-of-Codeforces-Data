#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(LL i=j;i<=k;i++)
#define read        freopen("in.txt", "r", stdin)
#define write       freopen("out.txt", "w", stdout)
#define pf          prLLf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define PB push_back
#define F first
#define S second
#define MP make_pair

typedef long long LL;

const int MAX = (1e5) + 5;


void solve()
{
    int a, b, c, d, k;
    int x, y;

    cin >> a >> b >> c >> d >> k;
    x = a / c;
    if(a%c) x++;
    y = b / d;
    if(b%d) y++;

    if(x + y <= k) cout << x << ' ' << y << endl;
    else cout << -1 << endl;

}

int main()
{
    ios::sync_with_stdio(false);
    //read;

    int tc;

    cin >> tc;

    FOR(tt,1,tc)
    solve();
    return 0;
}

