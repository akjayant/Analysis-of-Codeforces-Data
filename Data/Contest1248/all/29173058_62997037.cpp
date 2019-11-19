#include<stdio.h>
int rd(){
    int k=0;char c=getchar();
    while(c>'9'||c<'0')c=getchar();
    while(c>='0'&&c<='9')k=k*10+c-'0',c=getchar();
    return k;
}
int T,n,m,a;long long c[4];
int main(){
	T=rd();
	while(T--){
		n=rd(),c[0]=c[1]=c[2]=c[3]=0;
		for(int i=1;i<=n;++i)a=rd(),++c[a&1];
		m=rd();
		for(int i=1;i<=m;++i)a=rd(),++c[(a&1)+2];
		printf("%lld\n",c[1]*c[3]+c[2]*c[0]);
	}
	return 0;
}