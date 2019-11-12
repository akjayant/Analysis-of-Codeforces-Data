#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#define LL long long int
#define REP(i,n) for (int i = 1; i <= (n); i++)
#define Redge(u) for (int k = h[u],to; k; k = ed[k].nxt)
#define cls(s,v) memset(s,v,sizeof(s))
#define mp(a,b) make_pair<int,int>(a,b)
#define cp pair<int,int>
using namespace std;
const int maxn = 100005,maxm = 100005,INF = 0x3f3f3f3f,P = 1000000007;
inline int read(){
	int out = 0,flag = 1; char c = getchar();
	while (c < 48 || c > 57){if (c == '-') flag = 0; c = getchar();}
	while (c >= 48 && c <= 57){out = (out << 1) + (out << 3) + c - 48; c = getchar();}
	return flag ? out : -out;
}
int qpow(int a,int b){
	int ans = 1;
	for (; b; b >>= 1,a = 1ll * a * a % P)
		if (b & 1) ans = 1ll * ans * a % P;
	return ans;
}
int main(){
	int n = read(),m = read();
	printf("%d\n",qpow(((qpow(2,m) - 1) % P + P) % P,n));
	return 0;
}
