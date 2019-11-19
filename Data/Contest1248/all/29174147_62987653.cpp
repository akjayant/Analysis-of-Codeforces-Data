#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
inline int read(){
	int f=1,ans=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return f*ans;
}
using namespace std;
const int MAXN=100051;
int t,n,m,p[MAXN],q[MAXN],sadsad,asdsa,sdad,asdwewad;
signed main()
{
	t=read();
	while(t--){
		sadsad=asdsa=sdad=asdwewad=0;n=read();for(int i=1;i<=n;i++) p[i]=read();m=read();
		for(int i=1;i<=m;i++) q[i]=read();
		for(int i=1;i<=n;i++){
			if(p[i]%2)++sadsad;
			else ++asdsa;
		}
		for(int i=1;i<=m;i++){if(q[i]%2)++sdad;
			else ++asdwewad;
		}
printf("%lld\n",sadsad*sdad+asdsa*asdwewad);
	}
	return 0;
}