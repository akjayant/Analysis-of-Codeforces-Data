#include<bits/stdc++.h>
#define see(x) cout<<#x<<" = "<<x<<endl

using namespace std;
typedef long long ll;
int main(){
ll t;
cin>>t;
while(t--){
    ll a,b,c,ans=0;
    cin>>a>>b>>c;
    if(b>c/2){
        ans+=c/2;
        b-=c/2;
        if(a>b/2){
            ans+=b/2;
        }
        else
            ans+=a;
    }
    else{
        ans+=b;
    }
    cout<<ans*3<<endl;
}
return 0;
}
