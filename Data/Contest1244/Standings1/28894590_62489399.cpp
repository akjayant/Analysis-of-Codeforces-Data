#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
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
int n,ans;
ll k,sum;
ll s[N];
int a[N];
inline ll calc(ll x){
	if (x>=a[n]) return 0;
	int pos=lower_bound(a+1,a+n+1,x)-a;
	ll res=1ll*x*(n-pos+1);
	return s[pos]-res;
}
signed main(){
	//freopen("a.in","r",stdin);
	n=read(),k=read();
	for (int i=1;i<=n;++i) a[i]=read();
	sort(a+1,a+n+1);
	int l=a[1],r=a[n];
	ans=r-l;
	int lc=1,rc=1;
	while (k){
		if (a[lc]==a[n-rc+1]){
			ans=0;
			break;
		}
		if (lc<rc){
			int tmp=a[lc+1]-a[lc];
			if (k/lc<tmp){
				ans=min(ans,a[n-rc+1]-a[lc]-(k/lc));
				break;
			}else k-=(lc*tmp),l=a[lc+1],++lc,ans=min(ans,r-l);
		}else{
			int pos=n-rc+1;
			int tmp=a[pos]-a[pos-1];
			if (k/rc<tmp){
				ans=min(ans,a[n-rc+1]-a[lc]-(k/rc));
				break;
			}else k-=(rc*tmp),r=a[pos-1],++rc,ans=min(ans,r-l);
		}
		//printf("%d %d %d\n",lc,rc,k);
	}
	printf("%d\n",ans);
	return 0;
}
