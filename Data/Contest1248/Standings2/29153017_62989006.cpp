#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define ll long long
using namespace std;
const int _=1e5+7;
int read() {int x;scanf("%d",&x);return x;}
ll n,a[_];
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	sort(a+1,a+1+n);
	ll tot1=0,tot2=0;
	for(int i=1;i<=n/2;++i) tot1+=a[i];
	for(int i=n/2+1;i<=n;++i) tot2+=a[i];
	ll ans=tot1*tot1+tot2*tot2;
	cout<<ans<<"\n";
	return 0;
}