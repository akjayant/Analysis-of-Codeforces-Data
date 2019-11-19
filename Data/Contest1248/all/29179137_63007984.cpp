
#include<bits/stdc++.h>
using namespace std;

#define PI acos(-1)
#define hell 1000000007
#define HELL 998244353
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fix(n) cout << fixed << setprecision(n)
#define mset(a,n) memset(a,n,sizeof a)
#define rep(i,a,b) for (__typeof((b)) i=(a);i<(b);i++)
#define repp(i,a,b,p) for(__typeof((b)) i=(a);i<(b);i+=p)
#define ren(i,a,b) for(__typeof((a)) i=(a);i>=(b);i--)
#define renn(i,a,b,p) for(__typeof((a) i=(a);i>=(b);i-=p)
#define ADD(a,b,c) ((a)%c+(b)%c)%c
#define SUB(a,b,c) ((a)%c-(b)%c+c)%c
#define MUL(a,b,c) (((a)%c)*((b)%c))%c
#define lbd lower_bound
#define ubd upper_bound
#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define all(v) (v).begin(), (v).end()
#define sz(x) (ll)x.size()
#define endl "\n"
#define out(n) cout<<n<<" "
#define outl(n) cout<<n<<endl
#define line cout<<endl
#define bug(n) {outl(n);return;}
#define N 2505
#define pii pair<int,int>
#define M 1000000007


ll vpow(ll a,ll b){
	if(b==0)
		return 1;
	if(b==1)
			return a;
	ll temp=vpow(a,b/2);
	temp*=temp;
	temp%=M;
	if(b%2==0)
		return temp;
	temp=temp*a;
	temp%=M;
	return temp;
}

ll iverseMod(ll a,ll b){
	ll temp=vpow(b,M-2);
	ll ans=temp*a;
	ans%=M;
	return ans;
}
void solve(){
	ll n,m;
	cin>>n>>m;
	ll c=max(n,m);
	ll dp[c+1];
	dp[0]=1;
	dp[1]=1;
	rep(i,2,c+1){
		dp[i]=(i*dp[i-1])%M;
	}
	ll fact=1;
	ll ans=1;
	rep(x,1,n/2+1){
		ll temp=dp[x]*dp[n-2*x];
		temp%=M;
		ans+=iverseMod(dp[n-x],temp);
		ans%=M;

	}
	rep(x,1,m/2+1){
		ll temp=dp[x]*dp[m-2*x];
		temp%=M;
		ans+=iverseMod(dp[m-x],temp);
		ans%=M;
	}
	ans*=2;
	ans%=M;
	cout<<ans<<endl;


}
void prep(){

}
int main(){
    io;
    ll t=1;
    //cin>>t;
    prep();
    fix(12);
    while(t--)
        solve();
    return 0;
}
