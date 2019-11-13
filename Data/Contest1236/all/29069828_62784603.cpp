#include<bits/stdc++.h>
#define FOR(i, j, k) for(auto i = j; i <= k; i ++)
#define FORD(i, j, k) for(auto i = j; i >= k; i --)
#define maxC 1000000007
#define mn 100005

using namespace std;
long long a, b, c;

void setup()
{
    cin >> a >> b >> c;
    long long ans = 0;
    long long takeB = 0;
    while(takeB <= b)
    {
        long long num = min(a, (b - takeB) >> 1) * 3 + min(takeB, c >> 1) * 3;
        ans = max(ans, num);
        takeB ++;
    }
    cout << ans << '\n';
}

void xuly()
{

}

main()
{
    iostream::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin >> t;
    while(t --)
    {
        setup();
        xuly();
    }
    return 0;
}