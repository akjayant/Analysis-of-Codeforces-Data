#include<bits/stdc++.h>
using namespace std;
#define N 200003
#define LL long long
#define mod 998244353

int T,n,m;
int p[N],q[N];
LL ans1,ans2,ans;

inline int read(){
	int X=0,w=0;
	char ch=0;
	while (ch<'0' || ch>'9')
	  w|=ch=='-',ch=getchar();
	while (ch>='0' && ch<='9')
	  X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
	return w ? -X : X;
}

int main(){
	T=read();
	while (T--){
		ans1=ans2=0;
		n=read();
		for (int i=1;i<=n;i++){
		  	p[i]=read();
			if (p[i]%2==0) ans1++;
		}
		m=read();
		for (int i=1;i<=m;i++){
		  	q[i]=read();
			if (q[i]%2==0) ans2++;
		}
		ans=ans1*ans2;
		ans1=n-ans1;ans2=m-ans2;
		ans+=ans1*ans2;
		printf("%lld\n",ans);
	}
	return 0;
}