#include<bits/stdc++.h>
#define ll long long
const int N=1e5+5;
using namespace std;
ll read(ll &x){
	ll dat=0,oko=1;char chc=getchar();
	while(chc<'0'||chc>'9'){if(chc=='-')oko=-1;chc=getchar();}
	while(chc>='0'&&chc<='9'){dat=dat*10+chc-'0';chc=getchar();}
	x=dat*oko;return x;
}ll T,n,m,a[N],b[N],t1,t2;
int main(){
	read(T);
	while(T--){
		read(n),t1=0,t2=0;
		for(ll i=1;i<=n;i++){
			if(read(a[i])%2)t1++;
		}read(m);
		for(ll i=1;i<=m;i++){
			if(read(b[i])%2)t2++;
		}ll ans=t1*t2+(n-t1)*(m-t2);
		printf("%lld\n",ans);
	}return 0;
}
