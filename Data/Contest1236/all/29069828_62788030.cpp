#include<bits/stdc++.h>
#define FOR(i, j, k) for(auto i = j; i <= k; i ++)
#define FORD(i, j, k) for(auto i = j; i >= k; i --)
#define maxC 1000000007
#define mn 100005

using namespace std;
long long n, m;

long long subtract(long long a, long long b)
{
    if ((a -= b) < 0)
        a += maxC;
    return a;
}

long long power(long long a, long long b)
{
    long long result = 1;
    while(b)
    {
        if (b & 1)
            result = (result * a) % maxC;
        a = (a * a) % maxC;
        b >>= 1;
    }
    return result;
}

void setup()
{
    cin >> n >> m;
    long long ans = power(subtract(power(2, m), 1), n);
    cout << ans;
}

void xuly()
{

}

main()
{
    iostream::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    setup();
    xuly();
    return 0;
}