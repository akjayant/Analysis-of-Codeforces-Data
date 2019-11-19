#include<bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define sz(x) ((int)x.size())
#define ii pair<int,int>
#define ll long long
#define ppb pop_back
#define N 200005
#define MOD 1000000007
#define inf 2000000000
#define iii pair<pair<int,int>,int>
#define P 1000003
using namespace std;

int n;
ll k;
int a[N];
ll pre[N];

ll sf(int x,int vl) {

	return (ll)-(n-x+1)*vl+(pre[n]-pre[x-1]);

}

ll pr(int x,int vl) {

	return (ll)x*vl-pre[x];

}

bool ok(int val) {

	int r=0;

	for(int i=1;i<=n;i++) {

		while(r+1<=n && a[r+1]-a[i]<=val) r++;

		if(pr(i,a[i])+sf(r+1,a[i]+val)<=k) return 1;

	}

	int l=n+1;

	for(int i=n;i>=1;i--) {

		while(l-1>=1 && a[i]-a[l-1]<=val) l--;

		if(pr(l-1,a[i]-val)+sf(i,a[i])<=k) return 1; 

	} 

	return 0;

}

int main() {

	scanf("%d %lld",&n,&k);

	for(int i=1;i<=n;i++) scanf("%d",a+i);

	sort(a+1,a+1+n);

	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];

	int bas=0,son=1000000001;

	while(bas<=son) {

		int m=(bas+son)/2;

		if(ok(m)) son=m-1;
		else bas=m+1;

	}

	printf("%d",bas);

}