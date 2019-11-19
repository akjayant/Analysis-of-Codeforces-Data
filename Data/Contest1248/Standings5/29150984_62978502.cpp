#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
inline int read(){
	int sum(0);char ch(getchar());
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		sum=sum*10+ch-'0';
		ch=getchar();
	}
	return sum;
}
#define L long long
int t,n,m,a[100005],b[100005];
L tp1,tp2,tp3,tp4,ans;
int main(){
	t=read();
	while(t--){
		n=read();for(int i=1;i<=n;++i)a[i]=read();
		m=read();for(int i=1;i<=m;++i)b[i]=read();
		tp1=tp2=tp3=tp4=ans=0;
		for(int i=1;i<=n;++i)
			if(a[i]&1)++tp1;
		tp2=n-tp1;
		for(int i=1;i<=m;++i)
			if(b[i]&1)++tp3;
		tp4=m-tp3;
		ans=tp1*tp3+tp2*tp4;
		printf("%lld\n",ans);
	}
}