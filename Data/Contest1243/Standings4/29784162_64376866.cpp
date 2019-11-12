#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int main()
{
    ll n, k;
    
    cin >> k;
    
    while(k--)
    {
        cin >> n;
        
        vector<ll> V(n);
        
        for (ll i = 0; i < n; ++i)
            cin >> V[i];
        
        ll j = 0;
        
        ll ans = 1;
        
        sort(V.begin(), V.end());
        
        for (ll i = 1; i <= n; ++i)
        {
            while((V[j] < i) && (j < n)) ++j;
            
            if (j >= n)
                break;
            
            if ((n - j) >= i)
                ans = i;
        }
        
        cout << ans << endl;
    }
    
    return 0;
}
