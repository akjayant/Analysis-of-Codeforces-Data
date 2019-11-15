#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const ll maxn = 330;
const ll mod = 1e9+7;

ll n, m, q;
ll a[maxn][maxn];

int main()
{
    cin>> n;

    ll x = 1;
    for(ll j = 1; j <= n; j++)
    {
        if(j&1){
            for(ll i = 1; i <= n; i++)
            {
                a[i][j] = x;
                x++;
            }
        }
        else{
            for(ll i = n; i >= 1; i--)
            {
                a[i][j] = x;
                x++;
            }
        }
    }

    for(ll i = 1; i <= n; i++)
    {
        for(ll j = 1; j <= n; j++)
            cout<< a[i][j] <<" ";
        cout<<"\n";
    }
}