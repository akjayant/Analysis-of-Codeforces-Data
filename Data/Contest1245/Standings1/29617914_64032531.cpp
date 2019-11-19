#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll l, r;
int lb[64], rb[64];
bool ready[64][2][2][2][2];
ll memo[64][2][2][2][2];

bool feasible (bool hi, bool lo, int n, int bit) {
	if (lo&&lb[n]==1&&bit==0) return false;
	if (hi&&rb[n]==0&&bit==1) return false;
	return true;
}
bool newhi (int n, int bit, bool oldhi) {
	if (oldhi==false) return false;
	if (rb[n]==0) return true;
	return rb[n]==bit;
}
bool newlo (int n, int bit, bool oldlo) {
	if (oldlo==false) return false;
	if (lb[n]==1) return true;
	return lb[n]==bit;
}
ll C (int n, int k) {
	if (n<k) return 0;
	ll ans=1;
	for (int i=1; i<=k; ++i) {
		ans*=(n-i+1);
		ans/=i;
	}
	return ans;
}
ll dp (int n, bool ha, bool la, bool hb, bool lob) {
	if (n==-1) return 1;
	if (ha&&la&&hb&&lb&&rb[n]==1&&lb[n]==1) return 0;
	if (ready[n][ha][la][hb][lob]) return memo[n][ha][la][hb][lob];
	if (!ha && !la && !hb && !lb) {
		int np=n+1;
		ll ans=0;
		for (int k=0; k<=np; ++k) {
			ll tmp1 = C(np,k);
			ans+=tmp1*(1LL<<(np-k));
		}
		ready[n][ha][la][hb][lob] = 1;
		return memo[n][ha][la][hb][lob]=ans;
	}
	//a[n]=0, b[n]=1
	ll ans = 0;
	if (feasible(ha,la,n,0) && feasible(hb,lob,n,1))
		ans += dp(n-1, newhi(n,0,ha), newlo(n,0,la), newhi(n,1,hb), newlo(n,1,lob));
	//a=1, b=0
	if (feasible(ha,la,n,1) && feasible(hb,lob,n,0))
		ans += dp(n-1, newhi(n,1,ha), newlo(n,1,la), newhi(n,0,hb), newlo(n,0,lob));
	//a=0, b=0
	if (feasible(ha,la,n,0) && feasible(hb,lob,n,0))
		ans += dp(n-1, newhi(n,0,ha), newlo(n,0,la), newhi(n,0,hb), newlo(n,0,lob));
	ready[n][ha][la][hb][lob] = 1;
	return memo[n][ha][la][hb][lob]=ans;
}

int main() {
	ios::sync_with_stdio(0);
	int t; cin>>t;
	while (t--) {
		cin>>l>>r;
		for (int i=31; i>=0; --i) {
			lb[i]=(((1LL<<i)&l)?1:0);
			rb[i]=(((1LL<<i)&r)?1:0);
		}
		for (int i=31; i>=0; --i)
		for (int ha=0; ha<=1; ++ha)
		for (int la=0; la<=1; ++la)
		for (int hb=0; hb<=1; ++hb)
		for (int lob=0; lob<=1; ++lob) ready[i][ha][la][hb][lob]=0;
		cout<<dp(31,1,1,1,1)<<endl;
	}
	return 0;
}