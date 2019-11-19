#include<bits/stdc++.h>

using namespace std;

#define int long long

inline int read(){
	int x=0,f=1;
	char p=getchar();
	while(!isdigit(p)){
		if(p=='-') f=-1;
		p=getchar();
	}
	while(isdigit(p)) x=(x<<3)+(x<<1)+(p^48),p=getchar();
	return x*f;
}

int T,n,m,a[3],ans;

signed main(){
	T=read();
	while(T--){
		memset(a,0,sizeof(a));
		ans=0;
		n=read();
		for(int i=1;i<=n;i++){
			int x=read();
			int y=x&1;
			a[y]++;
		}
		m=read();
//		cout<<"m		"<<m<<endl;
		for(int i=1;i<=m;i++){
			int x=read();
			int y=x&1;
			ans+=a[y];
		}
		cout<<ans<<endl;
	}
	return 0;
}

