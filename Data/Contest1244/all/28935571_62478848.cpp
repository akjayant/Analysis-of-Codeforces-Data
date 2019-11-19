#include<bits/stdc++.h>
#define gcd __gcd
using namespace std;
using ll=long long;

ll n,p,w,d,g;
ll x,y,k;

int main(){
    cin>>n>>p>>w>>d;
    g=gcd(w,d);
    if(p%g){
        cout<<-1;
        return 0;
    }
    p/=g,w/=g,d/=g;
    for(ll i=0; i<d; ++i){
        if(!((p-i*w)%d)){
            x=i;
            break;
        }
    }
    for(ll i=0; i<w; ++i){
        if(!((p-i*d)%w)){
            y=i;
            break;
        }
    }
    k=(p-x*w-y*d)/(d*w);
    x+=d*k;
    if(k<0 || x+y>n){
        cout<<-1;
        return 0;
    }
    cout<<x<<' '<<y<<' '<<n-x-y;
    return 0;
}
