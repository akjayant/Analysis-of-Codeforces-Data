#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int T,a,b;
int gcd(int A,int B){return B?gcd(B,A%B):A;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&b);
		puts(gcd(a,b)==1?"Finite":"Infinite");
	}return 0;
}
