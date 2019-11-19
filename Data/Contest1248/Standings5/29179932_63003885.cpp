#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
long long mod=1e9+7;
long long x[maxn],y[maxn],z[maxn];
long long n,m;
void f(){
	z[1]=0;
	z[2]=2;
	y[1]=0;
	y[2]=2;
	x[1]=2;
	x[2]=4;
	for(int i=3;i<=100000;i++){
		x[i]=x[i-1]+x[i-2];
		x[i]%=mod;
		y[i]=y[i-1]+y[i-2];
		y[i]%=mod;
		z[i]=( z[i-1]+y[i]  )%mod;
	}
}
int main(){
	f();
	scanf("%lld%lld",&n,&m);
	cout<<( x[n]+z[m] )%mod<<endl;
	return 0;
}
