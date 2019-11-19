#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    if (n==1){
        cout<<1;
        return 0;
    }
    if (n==2){
        cout<<2;
        return 0;
    }
    vector<ll> p;
    ll s = sqrt(n);
    for (ll i=2; i<=s; i++){
        if (n%i==0){
            p.push_back(i);
        }
        while (n%i==0)
            n/=i;
    }
    if (n>2){
        p.push_back(n);
    }
    if (p.size()>1){
        cout<<1;
    }
    else
        cout<<p[0];
    return 0;
}
