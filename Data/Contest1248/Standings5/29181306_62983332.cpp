#include<bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
inline char get(){
	static char buf[30000],*p1=buf,*p2=buf;
	return p1==p2 && (p2=(p1=buf)+fread(buf,1,30000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	register char c=get();register int f=1,_=0;
	while(c>'9' || c<'0')f=(c=='-')?-1:1,c=get();
	while(c<='9' && c>='0')_=(_<<3)+(_<<1)+(c^48),c=get();
	return _*f;
}
int n;
int a[maxn],vis[maxn];
signed main(){
//	freopen("1.txt","r",stdin);
	n=read();
	for(register int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	int ans=0;
	int x=0,y=0;
	for(register int i=1;i<=n;i++){
		if(n-i+1>i){
			//cout<<"x:"<<a[n-i+1]<<" y:"<<a[i]<<endl;
			x+=a[n-i+1];
			y+=a[i];
		}
		else if(n-i+1==i){
			x+=a[i];
			break;
		}
		else break;
	}
	cout<<x*x+y*y<<endl;
	return 0;
}