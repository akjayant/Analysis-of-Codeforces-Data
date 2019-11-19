#include<bits/stdc++.h>
#define ll long long
#define dl double
#define fo(i,a,b) for (int i=a;i<=b;i++)
#define read(x) scanf("%d",&x)
#define println(x){printf(":\n");for (int tmpi=1;tmpi<=n;tmpi++)printf("%d ",x[i]);printf("\n");}
using namespace std;

const int N=1e5+7;
const int INF=0x3f3f3f3f;
const int M=1e9+7;

int n,m;
ll s[2],t[2];

void solve(){
	int n,m,x;
	memset(s,0,sizeof(s));
	memset(t,0,sizeof(t));
	read(n);
	fo(i,1,n){
		read(x);
		s[x&1]++;
	}
	read(m);
	fo(i,1,m){
		read(x);
		t[x&1]++;
	}
	ll ans=s[1]*t[1]+s[0]*t[0];
	printf("%I64d\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	for (int i=1;i<=T;i++)
	solve();
	return 0;
}


