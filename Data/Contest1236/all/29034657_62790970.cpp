#include <bits/stdc++.h>
#define rap(i,s,n) for(int i=s;i<=n;i++)
using namespace std;
#define P 1000000007
int qpow(int a,int k){a%=P; int ans=1; while(k){if(k&1) ans=1ll*ans*a%P; k>>=1; a=1ll*a*a%P;} return ans;}
int main(){
	int n,m; scanf("%d%d",&n,&m);
	printf("%d\n",qpow(qpow(2,m)+P-1,n));
	return 0;
}