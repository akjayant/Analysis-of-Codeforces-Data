#include<bits/stdc++.h>
using namespace std;
int T,n,m,n1,n0,m1,m0;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),n1=n0=m1=m0=0;
		for(int i=1,p;i<=n;i++)scanf("%d",&p),n1+=(p%2),n0+=(!(p%2));
		scanf("%d",&m);
		for(int i=1,p;i<=m;i++)scanf("%d",&p),m1+=(p%2),m0+=(!(p%2));
		printf("%I64d\n",1ll*n1*m1+1ll*n0*m0);
	}
}
