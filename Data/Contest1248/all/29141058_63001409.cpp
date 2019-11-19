#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,n,a) for (int i=n;i>=a;i--)
#define mst(a,i) memset(a,i,sizeof a)
#define ll long long
#define eps 1e-10 
const int mod = 1e9+7;
const int N = 1e5+6;

int n,m;
ll f[N],e[N],ans;

ll C(int x,int y){
	if(x<y||y<0||x<0)
		return 0;
	return (f[x]*((e[y]*e[x-y])%mod))%mod;
}

ll qpow(ll a,ll b){
    ll ans=1,base=a%mod;
    while(b){
        if(b&1)
            ans=(ans*base)%mod;
        base=(base*base)%mod;
        b>>=1;
    }
    return ans;
}

void cal(){
	f[0]=e[0]=1ll;
	rep(i,1,N-1){
		f[i]=(f[i-1]*i)%mod;
		e[i]=qpow(f[i],mod-2);
	}
}

void solve(){
	rep(i,0,m){
		//i==x==y
		ans=(ans+2*C(2*i,m-2*i))%mod;
		//i==x==y-1
		ans=(ans+C(2*i+1,m-2*i-1))%mod;
		//i==x==y+1
		ans=(ans+C(2*i-1,m-2*i+1))%mod;
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cal();
	cin>>n>>m;
	solve();
	swap(n,m);solve();
	cout<<(ans-2+mod)%mod<<endl;
	return 0;
}
/*

*/