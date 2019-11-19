#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#include<set>
#include<string>
#include<cmath>
#include<cstring>
#define FF first
#define SS second
#define ll long long
#define pb push_back
#define pm make_pair
using namespace std;
typedef pair<int,int> PII;
const int MAX = 2e5 + 5;
int n;
int tmp[MAX],out[MAX];
ll cc[5][MAX],c[5][MAX],a[MAX];
ll ans=1e18,tt=0;
vector<int> vv[MAX];
int cal(int x,int y) {
	bool bk[5];
	for(int i = 1; i<=3; i++) bk[i]=0;
	bk[x]=1;bk[y]=1;
	for(int i = 1; i<=3; i++) {
		if(bk[i]==0) return i;
	}
}
int main()
{
	cin>>n;
	for(int i = 1; i<=n; i++) scanf("%lld",&cc[1][i]);
	for(int i = 1; i<=n; i++) scanf("%lld",&cc[2][i]);
	for(int i = 1; i<=n; i++) scanf("%lld",&cc[3][i]);
	for(int u,v,i = 1; i<=n-1; i++) {
		scanf("%d%d",&u,&v);
		vv[u].pb(v);vv[v].pb(u);
	}
	int flag = 1,tar;
	for(int i = 1; i<=n; i++) {
		if(vv[i].size() >= 3) {flag = 0;break;}
		if(vv[i].size() == 1) tar = i;
	}
	if(flag == 0) {
		puts("-1");return 0;
	}
	for(int i = 1; i<=n; i++) {
		a[i] = tar;c[1][i]=cc[1][tar];c[2][i]=cc[2][tar];c[3][i]=cc[3][tar];
		for(auto x : vv[a[i]]) {
			if(x == a[i-1]) continue;
			else {tar = x;break;}
		}
	}
	for(int i = 1; i<=3; i++) {
		for(int j = 1; j<=3; j++) {
			if(i == j) continue;
			tmp[1]=i;tmp[2]=j;
			for(int k = 3; k<=n; k++) {
				tmp[k] = cal(tmp[k-1],tmp[k-2]);
			}
			tt=0;
			for(int k = 1; k<=n; k++) {
				tt += c[tmp[k]][k];
			}
			if(tt < ans) {
				ans = tt;
				for(int k = 1; k<=n; k++) {
					out[a[k]] = tmp[k];
				}
			}
		}
	}
	printf("%lld\n",ans);
	for(int i = 1; i<=n; i++) printf("%d%c",out[i],i == n ? '\n' : ' ');
	return 0 ;
}
