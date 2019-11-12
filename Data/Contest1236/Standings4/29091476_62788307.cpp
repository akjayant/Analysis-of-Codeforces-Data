#include <bits/stdc++.h>
#define MOD 1000000007
#define MOD1 998244353
#define ll long long int
#define endl "\n"
#define INF 1e+18
#define INF1 1e+9
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define mp make_pair
#define debx cout<<" X "<<endl;
#define deby cout<<" Y "<<endl;
#define debz cout<<" Z "<<endl;
using namespace std;

int main(){
    fastio;
    ll t;
    cin>>t;
    while(t--){
        ll a,b,c,aa,bb,cc;
        cin>>a>>b>>c;
        ll ans=0;
     /*   while(a && b>1){
            ans+=3;
            a--;
            b-=2;
        }
        while(c>1 && b){
            b--;
            ans+=3;
            c-=2;
        }
        cout<<ans<<endl;*/
        ll x=min(a,b/2);
        ll y=min(b-2*x,c/2);
        ans=3*(x+y);
        y=min(b,c/2);
        x=min((b-y)/2,a);
        ans=max(ans,3*(x+y));
        cout<<ans<<endl;
    }
}
