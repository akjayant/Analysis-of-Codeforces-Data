#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<algorithm>

#define rg register
#define il inline
#define MX (100000 + 5)
#define mod (1000000007)

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

int F[MX];
void init(){
	F[0] = F[1] = 1;
	for(rg int i = 2 ; i < MX ; ++i)
		F[i] = (F[i - 1] + F[i - 2]) % mod;
}

char str[MX];
int main(){
	init();
	scanf("%s" ,str);
	int lx ,ch ,len = strlen(str);
	long long Ans = 1;
	lx = 1;
	if(str[0] == 'm' || str[1] == 'w')	return puts("0") ,0;
	for(rg int i = 1 ; i < len ; ++i){
		if(str[i] == 'm' || str[i] == 'w'){
			puts("0");
			return 0;
		}
		if(str[i] == str[i - 1]){
			++lx;
		}
		else{
			if(str[i - 1] == 'u' || str[i - 1] == 'n'){
				Ans = Ans * F[lx] % mod;
			}
			lx = 1;
		}
	}
	if(str[len - 1] == 'u' || str[len - 1] == 'n')
		Ans = Ans * F[lx] % mod;
	printf("%I64d\n" ,Ans);
	return 0;
}
