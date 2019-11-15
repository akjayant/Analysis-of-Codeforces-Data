#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxx=1e3+10;
int main(){
    int t; cin>>t;
    while(t--){
        ll a,b; cin>>a>>b;
        ll x=__gcd(a,b);
        if(x==1){
            puts("Finite");
        }else{
            puts("Infinite");
        }
    }
}
