#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    if(n==1) {
        cout<<1<<endl;
        return 0;
    }
    ll ori = n;
    ll val = sqrt(n)+1;
    ll num = 0;
    ll pf = -1;
    for(ll i = 2;i<=val;i++) {
        if(n%i==0)
            num++,pf = i;
        while(n%i==0)
            n/=i;
        if(num>=2)
            break;
    }
    if(n!=1) {
        num++;
        pf = n;
    }
    if(num>=2) {
        cout<<1<<endl;
    }
    else if(num==1){
        cout<<pf<<endl;
    }
}