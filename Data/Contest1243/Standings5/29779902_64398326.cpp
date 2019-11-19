#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pb push_back
#define ss second
#define ff first
#define INF 1000000000000000001
#define PI 3.14159265358979323846L
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<pair<ll,ll> > vll;
typedef vector<pair<int,int> > vii ;
typedef pair<ll,ll> pll ;

int main()
{
    fast;
    int _ = 1;
    //cin >> _;
    while(_--)
    {
        ll n, x, ans = 0;
        cin >> n;
        x = n;
        vector<ll> v;
        for(ll i = 2; i * i <= n; i++)
        {
            if(x <= 1) break;
            if(x % i == 0)
            {
                v.pb(i);
                while(x % i == 0) x /= i;
            }
        }
        if(x > 1) v.pb(x);
        if(v.size() > 1)
            ans = 1;
        else if(v.size() == 0) ans = n;
        else
        {
            ans = v[0];
        }
        cout << ans << "\n";
    }
    return 0;
}
