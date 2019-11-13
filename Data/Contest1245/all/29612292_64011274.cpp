#include<bits/stdc++.h>
using namespace std;int T_T,a,b;
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main(){
	for(scanf("%d",&T_T);T_T--;){
		scanf("%d%d",&a,&b);
		if(gcd(a,b)==1)puts("Finite");else puts("Infinite");
	}
} 