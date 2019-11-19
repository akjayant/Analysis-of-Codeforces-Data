#include <bits/stdc++.h>

#define enter putchar('\n')
#define space putchar(' ')
#define N 100010
#define int long long

using namespace std;

inline int read(){
	int x=0;char c=getchar();bool y=1;
	for(;c<'0' || c>'9';c=getchar()) if(c=='-') y=0;
	for(;c>='0' && c<='9';c=getchar()) x=(x<<1)+(x<<3)+c-48;
	if(y) return x;
	return -x;
}

int n,a[N],k;

inline void solve(){
	int l=1,r=n,sl=1,sr=1;
	while(l<r && k>0){
		while(a[l]==a[l+1]) l++;
		while(a[r]==a[r-1] && l<r) r--;
		if(l==r) break;
		if(l<n-r+1) {
			int tim=min(k/l,(a[l+1]-a[l]));
			if(tim!=a[l+1]-a[l]) {a[l]+=tim;break;}
			a[l]+=tim;
			k-=tim*l;
			continue;
		}
		else{
			int tim=min(k/(n-r+1),(a[r]-a[r-1]));
			if(tim!=a[r]-a[r-1]) {a[r]-=tim;break;}
			a[r]-=tim;
			k-=tim*(n-r+1);
			continue;
		}
	}
	printf("%I64d\n",a[r]-a[l]);
	return;
}

inline void Input(){
	n=read(),k=read();
	for(int i=1;i<=n;i++)
	a[i]=read();
	sort(a+1,a+n+1);
	return;
}

signed main(){
	Input();
	solve();
	return 0;
}