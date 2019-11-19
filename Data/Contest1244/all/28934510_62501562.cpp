#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define chrng(n,a,b)      (((n)>=(a))&&((n)<=(b)))
#define clamp(n,a,b)      (((n)<(a))?(a):((((n)>(b))?(b):(n)))

int a[100005];
int ps[100005];

void solve(){
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	rep(i,0,n){
		ps[i+1]=ps[i]+a[i];
	}
	int L=0,U=a[n-1]-a[0],ans=-1;
	while(L<=U){
		int z=0;
		int m=(L+U)/2;
		rep(i,0,n){
			int e=a[i],f=m+e;
			int t=e*i-ps[i];
			int l=lower_bound(a,a+n,f)-a;
			if(l<n){
				t+=(ps[n]-ps[l])-(n-l)*f;
			}
			if(t<=k){z=1;break;}
		}
		// cout<<m<<" "<<z<<"\n";
		rep(i,0,n){
			int e=a[i],f=e-m;
			int t=(ps[n]-ps[i])-e*(n-i);
			int u=lower_bound(a,a+n,f)-a-1;
			if(u>=0){
				t+=(u+1)*f-(ps[u+1]);
			}
			if(t<=k){z=1;break;}
		}
		// cout<<m<<" "<<z<<"\n";
		if(z){
			ans=m;
			U=m-1;
		}
		else{
			L=m+1;
		}
	}
	cout<<ans;
}
signed main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}
