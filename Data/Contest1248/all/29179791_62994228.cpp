#include<stdio.h>
#include<iostream>
#define ll long long
#define mo 1000000007
using namespace std;
int n,m,f[100005][2][2];
int add(int a,int b){
	a+=b;return a>=mo?a-mo:a;
}
int main(){
	scanf("%d%d",&n,&m);
	if(n<m)swap(n,m);
	f[0][0][0]=1;
	for(int i=1;i<=n;i++){
		f[i][0][0]=f[i-1][1][0];
		f[i][1][1]=f[i-1][0][1];
		f[i][0][1]=add(f[i-1][1][0],f[i-1][0][0]);
		f[i][1][0]=add(f[i-1][0][0],f[i-1][1][0]);
	}
	ll a=add(add(f[n][0][0],f[n][1][1]),add(f[n][0][1],f[n][1][0])),b=add(add(f[m][0][0],f[m][1][1]),add(f[m][0][1],f[m][1][0]));
	printf("%I64d",(a+b-2+mo)%mo);
}
