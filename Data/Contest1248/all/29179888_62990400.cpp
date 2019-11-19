#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<vector>
#include<ctime>
#define LL long long
#define pii pair<int,int>
#define mk make_pair
#define fi first
#define se second
using namespace std;
const LL mod = 1e9 + 7;
const int N = 2e5 + 3;
int n,m;
inline int read(){
	int v = 0,c = 1;char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-') c = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		v = v * 10 + ch - 48;
		ch = getchar();
	}
	return v * c;
}
LL f[N][2];
int main(){
	n = read(),m = read();
	f[1][0] = 2;
	for(int i = 2;i <= max(n,m) + 1;++i){
		f[i][0] = (f[i - 1][0] + f[i - 1][1]) % mod;
		f[i][1] = f[i - 1][0];
	}
	printf("%d\n",(1ll * f[n][0] + f[n][1] + f[m][0] + f[m][1] - 2 + mod) % mod);
    return 0;
}

