#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod=1000000000+7;
const int maxn=100000+10;
ll A[maxn];
ll B[maxn];
int main(){
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	A[1]=2,A[2]=4,A[3]=6;
	for(int i=4;i<=n;i++)
		A[i]=((2*A[i-1])%mod-A[i-3]+mod)%mod;
	B[1]=A[n];
	B[2]=(B[1]+2)%mod;
	B[3]=(B[2]+2)%mod;
	for(int i=4;i<=m;i++)
		B[i]=((2*B[i-1])%mod-B[i-3]+mod)%mod;
	printf("%lld\n",B[m]);
return 0;
}