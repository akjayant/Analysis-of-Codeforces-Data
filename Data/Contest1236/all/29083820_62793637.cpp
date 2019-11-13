#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define NMAX 200005
using namespace std;
typedef long long ll;
const int MOD=1000000007;
ll a, b, c, d, q, i, ans, n, m;
ll lgput(ll n, ll p)
{
    ll r=1;
    while(p>0)
    {
        if(p%2==1)
        {
            r=(r*n)%MOD;
            p--;
        }
        else
        {
            n=(n*n)%MOD;
          //  r=(r*n)%MOD;
            p/=2;
        }
    }
    return r;
}
void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
}
int main()
{
    fast();
    cin>>n>>m;
    cout<<lgput(lgput(2,m)-1,n);
    return 0;
}
