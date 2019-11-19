//h'b'b'b
#include<map>
#include<cmath>
#include<queue>
#include<vector>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define pb push_back
#define LL long long
#define mkp make_pair
#define PLL pair<LL, LL>
#define lowbit(x) x & (-x)
#define PII pair<int, int>
#define Pque priority_queue 
using namespace std;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int EPS = 1e-6;

map<bool, LL> pp;
map<bool, LL> qq;
//0奇数
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		int p, q;
		pp.clear();
		qq.clear();
		for(int i = 1; i <= n; i++){
			scanf(" %d", &p);
			if(p & 1) pp[0]++;
			else pp[1]++;
		}
		int m;
		scanf("%d", &m);
		for(int i = 1; i <= m; i++){
			scanf(" %d", &q);
			if(q & 1) qq[0]++;
			else qq[1]++;
		}
		long long ans = pp[1] * qq[1] + qq[0] * pp[0];
		printf("%lld\n", ans);	
	}
	return 0;
}