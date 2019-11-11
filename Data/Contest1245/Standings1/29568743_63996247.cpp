#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<algorithm>

#define rg register
#define il inline

int read(){
	rg char k = getchar();
	int x = 0 ,flag = 1;
	while(k < '0' || k > '9'){
		if(k == '-')	flag = -1;
		k = getchar();
	}
	while(k >= '0' && k <= '9'){
		x = x * 10 + k - '0';
		k = getchar();
	}
	return x * flag;
}

int gcd(int a ,int b){
	return b ? gcd(b ,a % b) : a;
}

int main(){
	int t = read();
	while(t--){
		if(gcd(read() ,read()) == 1)	puts("Finite");
		else puts("Infinite");
	}
	return 0;
}