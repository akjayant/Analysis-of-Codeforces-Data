#include<bits/stdc++.h>
#define ll long long
const int N=1e5+5;
using namespace std;
ll read(ll &x){
	ll dat=0,oko=1;char chc=getchar();
	while(chc<'0'||chc>'9'){if(chc=='-')oko=-1;chc=getchar();}
	while(chc>='0'&&chc<='9'){dat=dat*10+chc-'0';chc=getchar();}
	x=dat*oko;return x;
}ll n,ans,l[N],t1,t2;
int main(){
	read(n);
	for(ll i=1;i<=n;i++)read(l[i]);
	sort(l+1,l+1+n);
	for(ll i=1;i<=(n>>1);i++)t1+=l[i];
	for(ll i=(n>>1)+1;i<=n;i++)t2+=l[i];
	printf("%lld\n",t1*t1+t2*t2);
	return 0;
}
