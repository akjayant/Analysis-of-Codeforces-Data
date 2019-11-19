#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>

#define rg register
#define il inline
#define ll long long

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

int main(){
	ll Ans = 0 ,k[2] = {0};
	int t = read();
	while(t--){
		Ans = 0 ,k[0] = k[1] = 0;
		int n = read();
		while(n--)	k[read() & 1]++;
		int m = read();
		while(m--){
			Ans += k[read() & 1];
		}
		printf("%I64d\n" ,Ans);
	}
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
