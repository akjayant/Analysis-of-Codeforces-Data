#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
int T;
int x,y,p,q;
ll ca,cb,ta,tb;
inline int read(){
	int x=0;scanf("%d",&x);return x;
} 
int a[1000001];
int main(){
	x=read();
	for(int i=1;i<=x;i++){
		a[i]=read();
	}
	sort(a+1,a+x+1);
	int di=x/2;
	ll a1=0,a2=0;
	for(int i=1;i<=di;i++){
		a1+=a[i];
	}
	for(int j=di+1;j<=x;j++){
		a2+=a[j];
	}
	printf("%lld",a1*a1+a2*a2);
	return 0;
} 