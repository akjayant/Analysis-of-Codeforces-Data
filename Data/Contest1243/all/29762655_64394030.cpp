#include<bits/stdc++.h>
using namespace std;
using ll=long long;
vector <ll> V;
int main(){
    long long n;
    ll cnt=0;
    scanf("%lld",&n);
    ll ans=n;
    for(ll i=2;i*i<=n;i++){
        int flag=1;
        for(auto p:V){
            if(p*p>i)break;
            if(i%p==0){
                flag=0;
                break;
            }
        }
        if(flag)V.push_back(i);
    }
    for(ll i=0;i<V.size();i++){
        if(n%V[i]==0){
            cnt++;
            ans=V[i];
            while(n%V[i]==0)n/=V[i];
            if(n==1)ans=V[i];
            else ans=1;
            break;
        }
    }
    printf("%lld",ans);
}
