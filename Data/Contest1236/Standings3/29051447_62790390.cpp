#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll mod=1e9+7;
ll power(ll x, ll y) 
{ 
    ll res = 1;     // Initialize result 
   
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x)%mod; 
   
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x)%mod;  // Change x to x^2 
    } 
    return res%mod; 
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b;
    cin >> a >> b;
    cout << power(power(2, b)-1, a);

    return 0;
}