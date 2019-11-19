#include<cstdio>
#include<cstring>
#include<ctime>
#include<iostream>

#define rg register
#define il inline
#define MX (32 + 3)
#define ll long long

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

int upper1[MX] ,upper2[MX];
ll dp[MX][2][MX][2];
int len1 ,len2;

ll dapai(ll pos1 ,int lim1 ,ll pos2 ,int lim2){
	if(pos1 == 0)	return 1;
	if(dp[pos1][lim1][pos2][lim2])	return dp[pos1][lim1][pos2][lim2];
	int upp1 = !lim1 ? 1 : upper1[pos1];
	int upp2 = !lim2 ? 1 : upper2[pos2];
	ll Ans = 0;
	if(pos1 > pos2){
		for(rg int i = 0 ; i <= upp1 ; ++i){
			Ans += dapai(pos1 - 1 ,lim1 && i == upp1 ,pos2 ,lim2);
		}
		return dp[pos1][lim1][pos2][lim2] = Ans;
	}
	for(rg int i = 0 ; i <= upp1 ; ++i){
		for(rg int j = 0 ; j <= upp2 ; ++j){
			if(i && j)	continue;
			Ans += dapai(pos1 - 1 ,lim1 && i == upp1 ,pos2 - 1 ,lim2 && j == upp2);
		}
	}
	return dp[pos1][lim1][pos2][lim2] = Ans;
}

ll solve(int up1 ,int up2){
	memset(dp ,0 ,sizeof(dp));
	if(up1 < up2)	std::swap(up1 ,up2);
	if(up1 == -1)	return 0;
	len1 = 0;
	int cp = up1;
	while(cp){
		upper1[++len1] = cp & 1;
		cp >>= 1;
	}
	len2 = 0;
	cp = up2;
	while(cp){
		upper2[++len2] = cp & 1;
		cp >>= 1;
	}
	return dapai(len1 ,true ,len2 ,true);
}

int main(){
	int t = read();
	while(t--){
		int l = read() ,r = read();
		if(!l || !r){
			if(!l && !r){
				puts("1");
				continue;
			}
			int aim = l > r ? l : r;
			printf("%I64d\n" ,solve(aim ,aim));
			continue;
		}
		printf("%I64d\n" ,solve(r ,r) - solve(r ,l - 1) * 2 + solve(l - 1 ,l - 1));
	}
	return 0;
}
