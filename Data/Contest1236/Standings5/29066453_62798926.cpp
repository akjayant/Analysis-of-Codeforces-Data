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
const int maxn = 100005,maxm = 100005,INF = 0x3f3f3f3f;
inline int read(){
	int out = 0,flag = 1; char c = getchar();
	while (c < 48 || c > 57){if (c == '-') flag = 0; c = getchar();}
	while (c >= 48 && c <= 57){out = (out << 1) + (out << 3) + c - 48; c = getchar();}
	return flag ? out : -out;
}
int main(){
	int n = read();
	for (int i = 1; i <= n; i++){
		for (int j = 1,t = 1; j <= n; j++,t ^= 1){
			if (t) printf("%d ",n * (j - 1) + i);
			else printf("%d ",n * (j - 1) + n - i + 1);
		}
		puts("");
	}
	return 0;
}
