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

const int maxn=1e5+5;

int n,a[maxn],ans1,ans2,ans;

inline bool cmp(int a,int b){
	return a>b;
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n,cmp);
	if(n&1){
		for(int i=1;i<=(n/2)+1;i++) ans1+=a[i];
		for(int i=(n/2)+2;i<=n;i++) ans2+=a[i];
	}
	else{
		for(int i=1;i<=(n/2);i++) ans1+=a[i];
		for(int i=(n/2)+1;i<=n;i++) ans2+=a[i];
	}
	ans=ans1*ans1+ans2*ans2;
	cout<<ans<<endl;
	return 0;
}