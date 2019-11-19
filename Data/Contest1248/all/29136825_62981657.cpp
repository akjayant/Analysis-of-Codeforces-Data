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
    t = 1;
    while( t-- )
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for(ll i=0;i<n;i++) cin >> a[i];
        ll a1 = 0;
        ll a2 = 0;
        sort(a.begin() , a.end());
        for(ll i=0;i<n/2;i++) a1 += a[i];
        for(ll i=n/2;i<n;i++) a2 += a[i];
        cout << a1*a1 + a2*a2 << "\n";
    }
}