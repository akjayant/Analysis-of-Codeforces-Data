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

int arr[100005];

void solve(){
	int n,p,d,w;
	cin>>n>>p>>w>>d;
	int k=__gcd(d,w);
	if(p%k){
		cout<<-1;
		return;
	}
	d/=k;
	w/=k;
	p/=k;
	// int l=(p-n*d)/(w-d),u=p/w;
	// while(u*w<=p)u++;
	// while(l*w+(n-l)*d>=p)l--;
	// if(l>n){
	// 	cout<<-1;
	// 	return;
	// }
	int id;
	rep(i,1,w){
		if(i*d%w==1){
			id=i;break;
		}
	}
	int r=p%w * id %w,x=(p-r*d)/w;
	// cout<<r<<" "<<x<<"\n";
	int z=n-x-r;
	if(z<0||x<0){
		cout<<-1;
		return;
	}
	cout<<x<<" "<<r<<" "<<z;
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
