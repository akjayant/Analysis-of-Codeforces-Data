#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e4+5;
 
int main()
{
    ll n;
    cin >> n;
    vector <ll> v;
    for(ll i=2; i*i<=n; i++) {
        if(n%i==0) {
            v.push_back(i);
            while(n%i==0) n/=i;
        }
    }
    if(n>1) v.push_back(n);
 
    if(v.size()==1) cout << v[0] << endl;
    else cout << 1 << endl;
}