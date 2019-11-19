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

ll n,m;

ll f[N];
ll g[N];
void solve(){
	cin>>n>>m;
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	f[0]=1;
	fo(i,0,max(n,m)){
		f[i]%=M;
		f[i+1]+=f[i];
		f[i+2]+=f[i];
	}
	ll ans=(f[m]+f[n]-1+M)*2%M;
	cout<<ans;
}

int main(){
	solve();
	return 0;
}


