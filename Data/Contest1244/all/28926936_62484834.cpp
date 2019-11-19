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
int T,n,q[1005];
char opt[1005];
int main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s",&opt);
		for(int i=1;i<=n;++i)q[i]=opt[i-1]-'0';
		int ans(n);
		for(int i=1;i<=n;++i)
			if(q[i]){ans=i-1;break;}
		for(int i=n;i;--i)
			if(q[i]){ans=min(n-i,ans);break;}
		if(ans^n)printf("%d\n",(n<<1)-(ans<<1));
		else printf("%d\n",n);
	}
}