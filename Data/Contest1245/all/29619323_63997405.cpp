#include<cstdio>
#include<iostream>
using namespace std;
int gcd(int x,int y){
	if(y==0)return x;
	return gcd(y,x%y);
}
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int a,b;
		scanf("%d%d",&a,&b);
		if(a<b)swap(a,b);
		if(gcd(a,b)>1)puts("Infinite");
		else puts("Finite");
	}
	return 0;
}
