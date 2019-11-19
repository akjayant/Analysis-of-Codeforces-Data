#include <bits/stdc++.h>

#define set(p) memset(p,-1,sizeof(p))
#define clr(p) memset(p,0,sizeof(p))
#define ll long long int
#define llu unsigned long long int
#define si(n)                   scanf("%d",&n)
#define sf(n)                   scanf("%lf",&n)
#define ss(n)                                   scanf("%s",n)
#define rep(i,a,n) for(i=(a);i<(n);i++)
#define pii pair<int,int>
#define pb(x) push_back(x)
#define v(x) vector<x>
#define dp_print(dp,i,j,type)  cout<<"dp-"<<type<<"["<<i<<"]["<<j<<"] -> "<< dp[i][j]<<"\n";

using namespace std;




map<ll,ll> mp;
ll ar[100010];
ll br[100010];
vector<ll> bc[3100];
vector<ll> ans[3100];


int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // cout<<(-3/2)<<"\n";

	ll i,j,n,m,t;
	cin>>n;
    ll tot = 0;
    rep(i,0,n){
        cin>>ar[i];
        tot = tot + ar[i];
    }

    sort(ar,ar+n);

    ll lim = n/2;
    ll po = 0;

    rep(i,0,lim){
        po = po+ar[i];
    }
    ll rem = tot - po;

    ll ans = po*po + rem*rem;
    cout<<ans<<"\n";



	return 0;
}