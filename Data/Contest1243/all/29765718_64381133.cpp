#include <bits/stdc++.h>
#define FOR(i,j,k) for(int i = j; i <= k; i ++)
#define FORD(i,j,k) for(int i = j; i >= k; i --)
#define mp make_pair
#define N 300005
//#define f first
//#define s second
//#define int long long
using namespace std;

const int MOD=1e9+7;
long long n;
long long res = 0;
int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    cin >> n;
    res = n;
    for(long long i = 2; i <= sqrt(n); i ++)
    {
        if(n % i == 0)
        {
            res = __gcd(res, i);
            res = __gcd(res, n/i);
        }
    }
    cout << res;
}
