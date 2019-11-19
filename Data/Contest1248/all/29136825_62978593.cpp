//AUTHOR : TIRTH JARSANIA
//COLLEGE : DAIICT

#include<bits/stdc++.h>
using namespace std;

#define bp __builtin_popcountll
#define ll long long int
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<ll,ll>
#define precision(x,d) cout<<fixed<<setprecision(d)<<x
#define minQueue priority_queue<pii,vector<pii>,greater<pii> > 
#define maxQueue priority_queue<pii> 
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

int main()
{
    FAST;
    ll t;
    cin >> t;
    while( t-- )
    {
        ll n, m;
        cin >> n ;
        ll o1 = 0 , e1 = 0 , o2 = 0 , e2 = 0;
        while(n--)
        {
            ll x;
            cin >> x;
            if( x%2 == 0 ) e1++;
            else o1++;
        }
        cin >> m;
        while( m-- )
        {
            ll x;
            cin >> x;
            if( x%2 == 0 )
                e2++;
            else
                o2++;
        }
        cout << e1*e2 + o2*o1 << "\n";
    }
}