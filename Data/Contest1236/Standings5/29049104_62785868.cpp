#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define lb lower_bound
#define pb push_back
#define mp make_pair
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
// #define int ll
using namespace std;
const int INF (1 << 30);
const ll LLINF (1LL << 55LL);
const int MOD = 1000000007;
const int MAX = 510000;
 
 
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll q;
    cin>>q;
    rep(i,q){
        ll a,b,c,ans=0,res=0;
        cin>>a>>b>>c;
        ll a1=a,b1=b,c1=c;
        ll s=min(b,c/2);
        res+=3*s;
        b-=s;c-=2*s;
        ll r=min(a,b/2);
        res+=3*r;
        b=b1;c=c1;
        s=min(a,b/2);
        ans+=3*s;
        a-=s;b-=2*s;
        r=min(b,c/2);
        ans+=3*r;
        cout<<max(res,ans)<<endl;
    }
    return 0;
}