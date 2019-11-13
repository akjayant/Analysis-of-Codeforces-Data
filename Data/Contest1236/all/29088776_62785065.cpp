#include <bits/stdc++.h>
#include <time.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL));
#define MOD 1000000007
#define INF LONG_LONG_MAX
#define MINF LONG_LONG_MIN

int main()
{
    FAST;
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        ll x = 0 ;
        ll take = min(b,c/2);
        b-=take;
        c-=2*take;
        x+=take;
        take = min(a,b/2);
        x+=take;
        cout<<x*3<<"\n";
    }   
    return 0;
}

