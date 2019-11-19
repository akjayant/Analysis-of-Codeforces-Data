#include<stdio.h>
int rd(){
	int k=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')k=k*10+c-'0',c=getchar();
	return k;
}
const int N=300001,M=1000000007;
long long n,m,f[N],s;
int main(){
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	n=rd(),m=rd(),f[1]=1,f[2]=2;
	for(int i=3;i<=n||i<=m;++i)f[i]=(f[i-1]+f[i-2])%M;
	s=(f[n]+f[m]-1)%M;
	printf("%lld\n",((s+s)%M+M)%M);
	return 0;
}