#include<bits/stdc++.h>
#define ll long long
#define dl double
#define fo(i,a,b) for (int i=a;i<=b;i++)
#define read(x) scanf("%lld",&x)
#define println(x){printf(":\n");for (int tmpi=1;tmpi<=n;tmpi++)printf("%d ",x[i]);printf("\n");}
using namespace std;

const int N=1e5+7;
const int INF=0x3f3f3f3f;
const int M=1e9+7;

int n,m;
ll s[N];
ll x,y;

void solve(){
	read(n);
	x=0,y=0;
	fo(i,1,n){
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	int l=1,r=n;
	while(l<r){
		x+=s[l];
		y+=s[r];
		l++;
		r--;
	}
	if (l==r) y+=s[r];
	ll ans=x*x+y*y;
	cout<<ans;
}

int main(){
//	int T;
//	scanf("%d",&T);
//	for (int i=1;i<=T;i++)
	solve();
	return 0;
}


