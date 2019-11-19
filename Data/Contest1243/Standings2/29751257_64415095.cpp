//be name khoda
#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int maxn = 100 * 1001;
const int mod = 1e9+7;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll pr = 0, adad;
    ll n; cin>> n;
    ll m = n;
    for(ll i = 2; i <= sqrt(n); i++)
        if(n%i == 0)
        {
            pr++;
            adad = i;
            while(n%i == 0)
                n /= i;
        }

    if(n > 1){
        pr++;
        adad = n;
    }

    if(m == 1) return cout<< 1, 0;
    if(pr == 1) return cout<< adad, 0;
    cout<< 1;
}
