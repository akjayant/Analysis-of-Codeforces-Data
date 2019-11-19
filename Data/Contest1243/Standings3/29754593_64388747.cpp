#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false);
    ll n; cin >> n;
    vector<ll> p;
    for(ll i=2;i*i<=n;i++)
        if(n%i==0) {
            p.push_back(i);
            while(n%i==0) n/=i;
        }
    if(n>1) p.push_back(n);
    if(p.size()==1) cout << p[0] << endl;
    else cout << 1 << endl;
    return 0;
}
