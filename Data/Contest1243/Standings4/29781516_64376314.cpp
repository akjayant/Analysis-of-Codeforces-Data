#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=998244353;
ll a[1010][1010];
ll cnt[1010][1010];
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};
int main(){
    ll k;cin>>k;
    while(k){
        k--;
        ll n;cin>>n;
        vector<ll>a(n+1);
        rep(i,n){
            ll b;cin>>b;
            a[b]++;
        }
        ll ans=0;
        ll cnt=0;
        for(int i=n;i>0;i--){
            cnt+=a[i];
            ans=max(ans,min(cnt,i*1LL));
        }
        cout<<ans<<'\n';
    }
}