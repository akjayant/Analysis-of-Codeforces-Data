#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
const int P=1e9+7;

int pwr(int x,int a){
	int s=1;
	for(;a;a>>=1,x=1ll*x*x%P)
		if(a&1)s=1ll*s*x%P;
	return s;
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%d",pwr((pwr(2,m)+P-1)%P,n));
	return 0;
}