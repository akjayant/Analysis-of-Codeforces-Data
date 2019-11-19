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

vector<ll> bc[3100];
vector<ll> ans[3100];

ll dp[100010][2][2];
ll mod = 1000000007LL;

//type 0 - continuous 2
//type 1 - single

ll solve(ll color, ll type,ll n){

    if(n<=0){
        return 0;
    }
    if(n==1){
        return 1;
    }

    if(dp[n][color][type]!=-1)
        return dp[n][color][type];

    ll ans = 0;

    if(color==1){

        if(type==0){
            ans = (ans + (solve(1,1,n-1) + solve(0,0,n-1))%mod)%mod;
        }else{
            ans = (ans + solve(0,0,n-1))%mod;
        }
    }else{
        if(type==0){
            ans = (ans + (solve(0,1,n-1) + solve(1,0,n-1))%mod)%mod;
        }else{
            ans = (ans + solve(1,0,n-1))%mod;
        }
    }

    dp[n][color][type] =  ans;
    return dp[n][color][type];

}

int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // cout<<(-3/2)<<"\n";

	ll i,j,n,m,t;
	cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    ll ans1 = solve(1,0,m);
    ll ans2 = solve(0,0,m);

    ll ans3 = solve(1,0,n);
    ll ans4 = solve(0,0,n);

    ll bc = ((ans3+ans4)%mod - 2 + mod)%mod;
    ll ans = (((ans1+ans2)%mod) +bc)%mod;

    cout<<ans<<"\n";



	return 0;
}