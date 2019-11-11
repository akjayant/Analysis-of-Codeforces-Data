#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int t,a,b;
int gcd(int n,int m){
	if(m==0)return n;
	return gcd(m,n%m);
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&a,&b);
		if(gcd(a,b)==1)puts("Finite");
		else puts("Infinite");
	}
	return 0;
}
