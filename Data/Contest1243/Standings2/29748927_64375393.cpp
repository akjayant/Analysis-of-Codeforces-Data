#include<bits/stdc++.h>
#define MOD 1000000007
#define INF LLONG_MAX
#define F first
#define S second
#define LB lower_bound
#define UB upper_bound
#define vc vector
#define vll vector<long long>
#define pll pair<long long,long long> 
#define pb push_back
#define all(v) v.begin(),v.end()
#define T ll test;cin>>test; while(test--)
#define rep(i,a,n) for(ll i=a;i<(long long)n;++i)
#define repr(i,n,a) for(ll i=n;i>(long long)a;--i)
#define endl '\n'
#define MAX 100005
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    T{
        ll n;
        cin>>n;
        vll a(n);
        rep(i,0,n){
            cin>>a[i];
        }
        sort(all(a),greater<ll>());
        ll mini=INF,ans;ll cnt=0,res=-INF;
        rep(i,0,n){
            mini=min(mini,a[i]);
            ++cnt;
            ans=min(cnt,mini);
            res=max(ans,res);
        }
        cout<<res<<endl;
    }




    return 0;
}
