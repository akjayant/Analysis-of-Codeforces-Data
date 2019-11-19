#include<bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define sz(x) ((int)x.size())
#define ii pair<int,int>
#define ll long long
#define ppb pop_back
#define N 1000005
#define MOD 1000000007
#define inf 2000000000
#define P 1000003
using namespace std;

int slot_mx,slot_mn,n;
ll k;
int a[N],b[N];
vector<int> mxa,mxb;

ll p(int x) {

	return (ll)x*(x+1);

}

ll sum(int l,int r) {

	return p(r)-p(l-1);

}

ll getmax(int l,int r,int slot_mn,int slot_mx) {

	int nxl=l+slot_mn/2;
	bool halfl=slot_mn&1;

	int nxr=r-slot_mx/2;
	bool halfr=slot_mx&1;

	return sum(nxr+1,r)+(halfr?nxr:0)+sum(nxl,nxr)-(halfl?nxl:0);

}

int get_mx_b() {

	int res=mxb.back();

	mxb.ppb();

	return res;

}

int get_mx_a() {

	int res=mxa.back();

	mxa.ppb();

	return res;

}

void solve(int cur,ll k) {

	if(cur>n) return ;

	if(slot_mx>=2) {

		ll mx=getmax(cur+1,n,slot_mn,slot_mx-2);

		if(mx>=k-2*cur) {

			int ia=get_mx_a();
			int ib=get_mx_b();

			a[ia]=cur;
			b[ib]=cur;

			slot_mx-=2;

			solve(cur+1,k-2*cur);

			return ;

		}

	}

	ll mx=getmax(cur+1,n,slot_mn-1,slot_mx);

	if(mx>=k-cur) {

		int ia=slot_mn;
		int ib=slot_mn--;

		a[ia]=cur;
		b[ib]=cur;

		solve(cur+1,k-cur);

		return ;

	}

	int ia=slot_mn--;
	int ib=slot_mn--;

	a[ia]=cur;
	b[ib]=cur;

	mxa.pb(ib);
	mxb.pb(ia);

	slot_mx+=2;

	solve(cur+1,k);

}

int main() {

	scanf("%d %lld",&n,&k);

	ll mn=(ll)n*(n+1)/2;
	ll mx=getmax(1,n,n,0);

	if(mn>k) {

		printf("-1");

		return 0;

	}

	slot_mn=n;

	solve(1,min(k,mx));

	printf("%lld\n",min(k,mx));

	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	printf("\n");
	for(int i=1;i<=n;i++) printf("%d ",b[i]);

}