#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>

#define rg register
#define il inline
#define ll long long
#define MX (100000 + 5)
#define mod (1000000007LL)

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

ll qpow(ll a ,ll b){
	if(!b)	return 1;
	if(b == 1)	return a;
	ll t = qpow(a ,b >> 1);
	if(b & 1)	return t * t % mod * a % mod;
	return t * t % mod;
}

ll dp[MX][2][3][2];
// dp[i][j][k][l] 
// ��ǰ�� i λ����� j
// ���� k ����ȵ���
// ����������������ȵ� 
int main(){
	int n = read() ,m = read();
	dp[1][0][1][0] = dp[1][1][1][0] = true;
	for(rg int i = 2 ; i <= n ; ++i){
		dp[i][0][1][1] = (dp[i - 1][1][1][1] + dp[i - 1][1][2][1]) % mod;
		dp[i][0][1][0] = (dp[i - 1][1][1][0]) % mod;
		dp[i][0][2][1] = (dp[i - 1][0][1][1] + dp[i - 1][0][1][0]) % mod;
		
		dp[i][1][1][1] = (dp[i - 1][0][1][1] + dp[i - 1][0][2][1]) % mod;
		dp[i][1][1][0] = (dp[i - 1][0][1][0]) % mod;
		dp[i][1][2][1] = (dp[i - 1][1][1][1] + dp[i - 1][1][1][0]) % mod;
		ll f1 = dp[i][0][1][0] + dp[i][1][1][0];
		ll f2 = dp[i][0][2][1] + dp[i][0][1][1] + dp[i][1][2][1] + dp[i][1][1][1];
		//printf("%I64d %I64d\n" ,f1 ,f2);
	}
	ll f1[333][2][2];
	memset(f1 ,0 ,sizeof(f1));
	//memset(F ,0 ,sizeof(F));
	f1[1][1][0] = 1 ,f1[1][0][0] = 1;
	ll _Ans = (dp[n][0][2][1] + dp[n][0][1][1] + dp[n][1][2][1] + dp[n][1][1][1]) % mod;
	
	for(rg int i = 2 ; i <= m ; ++i){
		int k = (i - 1) & 1;
		f1[i & 1][1][0] = (f1[k][0][1] + f1[k][0][0]) % mod;
		f1[i & 1][1][1] = (f1[k][1][0]);
		
		f1[i & 1][0][0] = (f1[k][1][1] + f1[k][1][0]) % mod;
		f1[i & 1][0][1] = (f1[k][0][0]);
	}
	ll Ans = f1[m & 1][1][0] + f1[m & 1][0][0] + f1[m & 1][1][1] + f1[m & 1][0][1] + _Ans; 
	printf("%I64d\n" ,(Ans) % mod);
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
