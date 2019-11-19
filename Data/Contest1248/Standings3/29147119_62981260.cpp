#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6+10 ;

ll T ;
ll n ;
ll lll , out , ji2 , ou2 ;
ll now ;
int main ()
{
    cin >>T ;
    while (T--)
    {
        lll = out = ji2 = ou2 = 0 ;
            cin >> n;
        for (ll i = 1 ; i <= n ; i++)
        {
            cin >> now;
            if (now % 2)
                lll++ ;
            else
                out++ ;
        }
        scanf ("%lld" , &n) ;
        for (ll i = 1 ; i <= n ; i++)
        {
            cin >>now;
            if (now % 2)
                ji2++ ;
            else
                ou2++ ;
        }
        ll res = lll * ji2 + out * ou2 ;
        cout <<res<<endl;
    }
}
