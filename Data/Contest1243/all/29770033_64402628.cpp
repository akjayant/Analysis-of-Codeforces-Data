#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n,ans;
    cin>>n;
    ans=n;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0){
                n/=i;
            }
            if(n==1){
                ans=i;
            }else{
                ans=1;
            }
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}