#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
//ll ppow(ll x,int y){
//    ll res=1;
//    while(y){
//        if(y&1) res=(res*x)%mod;
//        x=(x*x)%mod;
//        y>>=1;
//    }
//    return res;
//}
int main(){
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        int a,b,c;
        cin>>a>>b>>c;
        int t1=min(b,c/2);
        int ans=t1*3;
        b-=t1;
        ans+=3*min(a,b/2);
        cout<<ans<<endl;
    }
    return 0;
}
