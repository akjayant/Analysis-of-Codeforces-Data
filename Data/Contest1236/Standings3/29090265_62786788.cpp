#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll t,a,b,c;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll i,j,k;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        ll a1=a;
        ll b1=b;
        ll c1=c;
    ll stp=min(b,c/2);
    ll ans=0;
    ans+=3*stp;
    b-=stp;
    stp=min(a,b/2);
    ans+=3*stp;
    
    ll stp1=min(a1,b1/2);
    ll ans1=0;
    ans1+=3*stp1;
    b1-=2*stp1;
    stp1=min(b1,c1/2);
    ans1+=3*stp1;
    cout<<max(ans1,ans)<<"\n";;
    }
    return 0;
}