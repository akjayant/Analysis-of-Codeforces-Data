#include <bits/stdc++.h>
using namespace std;
int ans , t , a, b , c , d ;
int main()
{
   // freopen("x.inp","r",stdin);
    cin>>t;
    while ( t-- )
    {
        cin>>a>>b>>c;
        ans = 0 ;
        d =  min( b , c/ 2)  ;
        ans +=  3 * d;
        b -= d ;
        ans += 3 * min( a , b/2 ) ;
        cout<<ans<<"\n" ;
    }
    return 0;
}
