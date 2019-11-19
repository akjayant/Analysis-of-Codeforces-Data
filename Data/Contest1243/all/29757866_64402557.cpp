#include<bits/stdc++.h>
using namespace std;
const int N=5100;
typedef long long ll;
const ll MOD=1e9+7LL;
ll phi(ll n) {
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll gc=n;
    for (ll i = 2; i*i <= n; ++i)
    {
    	if(n%i==0)
    	{
    		gc=__gcd(gc,i);
    		gc=__gcd(gc,n/i);

    	}
    }
    cout<<gc<<"\n";
    return 0;   
}