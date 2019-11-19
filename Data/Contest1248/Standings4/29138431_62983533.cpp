
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        for(int ii=1;ii<=20;ii++);
        ll nnn,nb;
        cin>>nnn ;
        ll ao=0,aj=0,bo=0,bj=0;
        ll k;
        for(ll i=1;i<=nnn;i++){
            cin>>k;
            if(k%2==0)ao++;
            else aj++;
        }
        cin>>nb;
        for(ll i=1;i<=nb;i++){
            ll k;
            cin>>k;
            if(k%2==0)bo++;
            else bj++;
        }for(int ii=1;ii<=20;ii++);
        long long ans=0;for(int ii=1;ii<=20;ii++);
        ans=1ll*(ao*bo)+(aj*bj);
        cout<<ans<<endl;for(int ii=1;ii<=20;ii++);for(int ii=1;ii<=20;ii++);

    }
    return 0;
}
