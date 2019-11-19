#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <stdlib.h>
using namespace std;
typedef long long int lld;
typedef long double ld;
lld val[111111][4],dp[111111][4][4],ans[111111];
vector<int> v[111111];
lld recur(int now,int left,int s,int z,int z2){
	lld ans = val[now][s];
	int tmp = 0;
	for(int e=0;e<v[now].size();e++){
		int next = v[now][e];
		if(next!=left){
			if(tmp==0) {
				for(int q=1;q<=3;q++){
					if(s!=q&&z!=q){
						ans += recur(next,now,z,q,-1);
					}
				}
				tmp = 1;
			}else if(tmp==1){
				for(int q=1;q<=3;q++){
					if(s!=q&&z2!=q){
						ans += recur(next,now,z2,q,-1);
					}
				}
			}
		}
	}
	return ans;
}
void recur2(int now,int left,int s,int z,int z2){
	ans[now] = s;
	int tmp = 0;
	for(int e=0;e<v[now].size();e++){
		int next = v[now][e];
		if(next!=left){
			if(tmp==0) {
				for(int q=1;q<=3;q++){
					if(s!=q&&z!=q){
						recur2(next,now,z,q,-1);
					}
				}
				tmp = 1;
			}else if(tmp==1){
				for(int q=1;q<=3;q++){
					if(s!=q&&z2!=q){
						recur2(next,now,z2,q,-1);
					}
				}
			}
		}
	}
}
int main(void){
	int n;
	scanf("%d",&n);
	for(int e=0;e<111111;e++) for(int p=0;p<4;p++) for(int q=0;q<4;q++) dp[e][p][q] = 1e18;
	for(int e=1;e<=n;e++) scanf("%lld",&val[e][1]);
	for(int e=1;e<=n;e++) scanf("%lld",&val[e][2]);
	for(int e=1;e<=n;e++) scanf("%lld",&val[e][3]);
	for(int e=0;e<n-1;e++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int e=1;e<=n;e++){
		if(v[e].size()>2){
			printf("-1");
			return 0;
		}
	}
	lld mm = 1e18,f,s,t;
	for(int e=1;e<=3;e++){
		for(int p=1;p<=3;p++){
			for(int q=1;q<=3;q++){
				if(e==p||p==q||e==q) continue;
				lld now = recur(1,-1,e,p,q);
				if(now<mm){
					mm = now;
					f = e;
					s = p;
					t = q;
				}
			}
		}
	}
	printf("%lld\n",mm);
	recur2(1,-1,f,s,t);
	for(int e=1;e<=n;e++) printf("%d ",ans[e]);
	return 0;
}