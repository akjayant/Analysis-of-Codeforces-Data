#include<bits/stdc++.h>
using namespace std;
long long n,f;
int main(){
	scanf("%I64d",&n);
	f=0;
	if(n%2==0){
		f=2;
	}
	else
		for(long long i=3;i*i<=n;i+=2){
			if(n==n/i*i){
				f=i;break;
			}
		}
	if(f==0){
		printf("%I64d",n);
	}
	else{
		while(n>1 && n==n/f*f){
			n/=f;
		}
		if(n==1)
			printf("%I64d",f);
		else
			printf("1");
	}
	return 0;
} 
