#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read(){
	int f=1,ans=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}
int G(double x){if((int)x==x) return x;return (int)x+1;}
void solve(){
	int a=read(),b=read(),c=read(),d=read(),k=read();
	int s1=G(double(a)/(double)c),s2=G(double(b)/(double)d);
	if(s1+s2>k){printf("-1\n");return;}
	printf("%d %d\n",s1,s2);return;
}
int main(){
	int T=read();
	while(T--) solve();
}
