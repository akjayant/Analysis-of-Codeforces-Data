#include<bits/stdc++.h>
using namespace std;
#define ll int
ll t,n;
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll i,j,k;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>s;
        s=" "+s;
        vector<ll>v;
        for(i=1;i<=n;i++){
            if(s[i]=='1'){
                v.push_back(i);
            }
        }
        if(v.size()==0){
            cout<<n<<"\n";
        } else if(v.size()==1){
            ll pos = v[0];
            ll ans=max(n+1,2*pos);
            ans=max(ans,2*(n-pos+1));
            cout<<ans<<"\n";
        } else {
            ll fpos = v[0];
            ll lpos = v[v.size()-1];
            ll ans=max(n+1,2*lpos);
            ans=max(ans,2*(n-fpos+1));
            ans=max(ans,fpos-1+n-lpos+2*(lpos-fpos+1));
            ans=max(ans, n+(ll)v.size());
            cout<<ans<<"\n";
        }
    }
    return 0;
}