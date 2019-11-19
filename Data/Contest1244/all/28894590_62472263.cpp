#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,w=1;
	char ch=0;
	while (ch<'0' || ch>'9'){
		ch=getchar();
		if (ch=='-') w=-1;	
	}
	while (ch<='9' && ch>='0'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*w;
}
const int N=1e5+5;
ll n,p,w,d;
int main(){
	//freopen("a.in","r",stdin);
	n=read(),p=read(),w=read(),d=read();
	for (ll i=0;i<=100000;++i){
		ll k=i*d;
		if (k>p) break;
		if ((p-k)%w) continue;
		if (i+((p-k)/w)<=n)
			return printf("%lld %lld %lld\n",((p-k)/w),i,n-i-((p-k)/w)),0;
	}
	puts("-1");
	return 0;
}
