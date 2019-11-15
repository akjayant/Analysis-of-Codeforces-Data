#include<bits/stdc++.h>
using namespace std;


int gcd(int x,int y){
	if(y==0)return x;
	return gcd(y,x%y);
}
int T;
int main(){
	scanf("%d",&T);
	while(T--){
		int a,b;
		scanf("%d%d",&a,&b);
		if(gcd(a,b)==1)puts("Finite");
		else puts("Infinite");
	}
	return 0;
}
