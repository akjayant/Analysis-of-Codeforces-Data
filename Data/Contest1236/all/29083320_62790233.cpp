#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;
ll n=2;
ll power(ll y){
    if(!y)
        return 1;
    ll t=power(y/2)%M;
    if(y&1)
        return n%M*t%M*t%M;
    return t%M*t%M;
}
int main(){
    ll p,a,b,r;
    cin>>a>>b;
    n=power(b)-1;
    cout<<power(a);
	return 0;
}
