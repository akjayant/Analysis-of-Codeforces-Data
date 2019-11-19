#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define ll long long
using namespace std;
const int _=1e5+7;
int read() {int x;scanf("%d",&x);return x;}
int a[_],b[_];
int main(){
	int T=read();
	while(T-->0) {
		ll n=read(),tot1=0,tot2=0;
		for(int i=1;i<=n;++i) a[i]=read(),tot1+=a[i]&1;
		int m=read();
		for(int i=1;i<=m;++i) b[i]=read(),tot2+=b[i]&1;
		ll ans=tot1*tot2+(n-tot1)*(m-tot2);
		cout<<ans<<"\n";
	}
	return 0;
}