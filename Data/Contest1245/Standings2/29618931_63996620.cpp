#include <bits/stdc++.h>

using namespace std;
const int maxn = 200006;
typedef long long ll;

int main() {

    ll t;
    cin>>t;
    while (t--) {
        ll a,b;
        cin>>a>>b;
        if (__gcd(a,b)==1) {
            cout<<"Finite"<<endl;
        }else {
            cout<<"Infinite"<<endl;
        }
    }


    return 0;
}
