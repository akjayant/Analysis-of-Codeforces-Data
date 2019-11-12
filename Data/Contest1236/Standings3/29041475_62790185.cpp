#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;

long long tinh( int x , int y)
{
    if ( y==0 ) return 1;
    if ( y==1 ) return x;
    long long res = tinh( x , y/2 );
    res = res * res ;
    res %= mod ;
    if ( y%2 == 1 ) res *= x;
    res %= mod ;
    return res;
}
long long n,m;
int main()
{
    //freopen("x.inp","r",stdin);
    cin>>n>>m;
    long long ans = 0;
    ans = tinh( 2 , m );

    ans -= 1;

    ans = tinh(  ans , n  );

    cout<<ans;

    return 0;
}
