//be name khoda
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll maxn = 3e5+10;
const ll mod = 1e9+9;
const ll len = 550;

ll n, m;
ll a[maxn];

int main()
{
    ll q; cin>> q;
    while(q--)
    {
        ll a, b; cin>> a >> b;
        if(__gcd(a,b) > 1)
            cout<<"Infinite";
        else
            cout<<"Finite";
        cout<<"\n";
    }
}
