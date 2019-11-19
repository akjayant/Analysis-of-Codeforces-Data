#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;

ll gcd(ll a,ll b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

void solve(){
    ll n,p,w,d; //w>=d
    cin>>n>>p>>w>>d;
    ll g=gcd(w,d);
    if(p%g>0){
        cout<<-1<<endl;
        return;
    }
    p/=g; w/=g; d/=g;
    ll cnt=0ll;
    while(p>=0){
        if(p%w==0){
            if(cnt+p/w<=n){
                ll l=n-p/w-cnt;
                cout<<p/w<<" "<<cnt<<" "<<l<<endl;
            }else{
                cout<<-1<<endl;
            }
            return;
        }
        cnt++;
        p-=d;
    }

    cout<<-1<<endl;

    return;
}


int main() {
    solve();
    return 0;
}
