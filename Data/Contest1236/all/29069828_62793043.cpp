#include<bits/stdc++.h>
#define FOR(i, j, k) for(auto i = j; i <= k; i ++)
#define FORD(i, j, k) for(auto i = j; i >= k; i --)
#define maxC 1000000007
#define mn 3003

using namespace std;
int n, a[mn][mn];

void setup()
{
    cin >> n;
    int val = n * n;
    FOR(i, 1, n)
    {
        if (i & 1)
        {
            FOR(j, 1, n)
                a[j][i] = val --;
        }
        else
        {
            FORD(j, n, 1)
                a[j][i] = val --;
        }
    }
    FOR(i, 1, n)
    {
        FOR(j, 1, n)
            cout << a[i][j] << ' ';
        cout << '\n'; 
    }
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