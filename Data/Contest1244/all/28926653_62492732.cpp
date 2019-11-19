#include<bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define sz(x) ((int)x.size())
#define ii pair<int,int>
#define ll long long
#define ppb pop_back
#define N 200005
#define MOD 1000000007
#define inf 2000000000
#define iii pair<pair<int,int>,int>
#define P 1000003
using namespace std;

int n;
ll ans=(ll)inf*inf;
int c[3][N];
int res[N];
int cc[N];
vector<int> a;
vector<int> v[N];

ll solve(int node) {

	for(int i:v[node]) {

		if(cc[i]!=-1) continue ;

		int ok[3]={0};

		for(int j:a) ok[j]=1;

		for(int j=0;j<3;j++) {

			if(!ok[j]) {

				cc[i]=j;
				a.erase(a.begin());
				a.pb(j);

			}

		}

		return solve(i)+c[cc[i]][i];

	}

	return 0;

}

void goo() {

	for(int i=1;i<=n;i++) res[i]=cc[i];

}

int main() {

	scanf("%d",&n);

	for(int i=0;i<3;i++) {

		for(int j=1;j<=n;j++) scanf("%d",c[i]+j);

	}

	for(int i=1;i<n;i++) {

		int x,y;

		scanf("%d %d",&x,&y);

		v[x].pb(y);
		v[y].pb(x);

	}

	vector<int> lf;

	for(int i=1;i<=n;i++) {

		if(sz(v[i])==1) lf.pb(i);

	}

	if(sz(lf)>2) {

		printf("-1");

		return 0;

	}

	for(int i=0;i<3;i++) {

		for(int j=0;j<3;j++) {

			if(i==j) continue ;

			memset(cc,-1,sizeof(cc));

			cc[lf[0]]=i;
			cc[v[lf[0]][0]]=j;

			a.clear();

			a.pb(i);a.pb(j);

			ll bf=ans;

			ans=min(ans,solve(v[lf[0]][0])+c[i][lf[0]]+c[j][v[lf[0]][0]]);

			if(ans!=bf) goo();

		}

	}

	printf("%lld\n",ans);

	for(int i=1;i<=n;i++) printf("%d ",res[i]+1);

}