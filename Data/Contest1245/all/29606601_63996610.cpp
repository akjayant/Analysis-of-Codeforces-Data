#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=2e5 + 5;
const ll mod=1e9 + 7;
#define debug(x) cerr<<#x<<" is "<<x<<endl;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;

    while(t-->0){
        ll a,b;
        cin>>a>>b;
        if(__gcd(a,b)==1)cout<<"Finite\n";
        else cout<<"Infinite\n";
    }
}

