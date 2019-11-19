#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>

#define rg register
#define il inline
#define ll long long
#define MX (100000 + 5)

int read(){
	rg char k = getchar();
	int x = 0 ,flag = 1;
	while(k < '0' || k > '9')	k = getchar();
	while(k >= '0' && k <= '9'){
		x = x * 10 + k - '0';
		k = getchar();
	}
	return x;
}

int A[MX];
int main(){
	int n = read();
	for(rg int i = 1 ; i <= n ; ++i){
		A[i] = read();
	}
	std::sort(A + 1 ,A + 1 + n);
	ll tmp = 0 ,Ans = 0;
	for(rg int i = 1 ; i <= (n >> 1) ; ++i)
		tmp += A[i];
	Ans += tmp * tmp;
	tmp = 0;
	for(rg int i = (n >> 1) + 1 ; i <= n ; ++i)
		tmp += A[i];
	Ans += tmp * tmp;
	printf("%I64d\n" ,Ans);
	return 0;
}
/*
3
3
1 3 2
2
0 3

1
1
1
1

1
2
1
1

*/
