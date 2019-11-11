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
int T, a, b;
int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    cin >> T;
    while(T --)
    {
        cin >> a >> b;
        if(__gcd(a, b) == 1) cout << "Finite";
        else cout << "Infinite";
        cout << "\n";
    }

}
