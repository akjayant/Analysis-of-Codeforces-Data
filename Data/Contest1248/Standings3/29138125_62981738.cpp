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
#define LL long long
#define mkp make_pair
#define PLL pair<LL, LL>
using namespace std;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

map<bool, LL> pp;
map<bool, LL> qq;
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
