#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main() {
    ll n;
    cin >> n;
    vector<ll> p;
    for(ll i=2;i*i<=n;++i) {
        if(n%i==0) {
            p.push_back(i);
            while(n%i==0)
                n/=i;
        }
    }
    if(n!=1)
        p.push_back(n);
    if(p.size()==1) {
        if(p[0]==2)
            cout << 2 << endl;
        else
            cout << p[0] << endl;
    } else
        cout << 1 << endl;

}
