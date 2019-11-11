#include<stdio.h>
#include<numeric>

int main(){
	int a, b, t;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &a, &b);
		puts(std::gcd(a, b)==1?"Finite":"Infinite");
	}
	return 0;
}
