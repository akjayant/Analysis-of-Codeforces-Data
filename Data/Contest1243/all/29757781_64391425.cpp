#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,g;
int main(){
    cin>>n;
    g=n;
    if(n==1)cout<<1;
    else if(n==2)cout<<2;
    else {
        for(ll i=2;i*i<=n;i++) {
            if(n%i==0)g=__gcd(g,i),g=__gcd(g,n/i);
        }
        cout<<g<<endl;
    }
}
