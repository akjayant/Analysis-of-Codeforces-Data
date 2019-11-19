#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define vl vector<ll>


using namespace std;

int main() 
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    
    ll x1 = b / c;
    ll x2 = b % c;
    
    ll k = -1;
    
    for(ll i = 0;i < c;i++)
        if((i * d) % c == x2)
        {
            k = ((i * d) - x2) / c;
            break;
        }
    
    if(k == -1 || k > x1 || (k * c + x2) / d + x1 - k > a)
        cout << -1;
    else
        cout << x1 - k << ' ' << (k * c + x2) / d << ' ' << a - x1 + k - (k * c + x2) / d;
    
}