#include<bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define pb push_back
#define ii pair<int,int>
#define ppb pop_back
#define orta ((bas+son)/2)
#define st first
#define nd second
#define ll long long
#define N 600005
#define inf 1000000000
#define MOD 1000000007
#define fast_io() cin.tie(0),cout.tie(0),ios_base::sync_with_stdio(false)
using namespace std;

int n;
ii a[N];
int c[N],k[N];
int ata[N],it[N];

int find(int x) {

	if(ata[x]==x) return x;

	return ata[x]=find(ata[x]);

}

ll gc(int x,int y) {

	if(x==y) return c[x];

	return (ll)(abs(a[x].st-a[y].st)+abs(a[x].nd-a[y].nd))*(k[x]+k[y]);

}

int main() {

	scanf("%d",&n);

	for(int i=1;i<=n;i++) {

		scanf("%d %d",&a[i].st,&a[i].nd);

	}

	for(int i=1;i<=n;i++) {

		scanf("%d",c+i);

	}

	for(int i=1;i<=n;i++) {

		scanf("%d",k+i);

	}

	vector<pair<ll,ii>> e;

	for(int i=1;i<=n;i++) {

		for(int j=i;j<=n;j++) {

			e.pb({gc(i,j),{i,j}});

		}

	}

	for(int i=1;i<=n;i++) {

		ata[i]=i;

	}

	sort(e.begin(),e.end());

	vector<ii> es;
	vector<int> stat;

	ll ans=0;

	for(auto ed:e) {

		int x=ed.nd.st;
		int y=ed.nd.nd;
		int dx=find(x);
		int dy=find(y);

		ll c=ed.st;

		if(x==y) {

			if(!it[dx]) {

				it[dx]=1;
				stat.pb(x);

				ans+=c;

			}

		}
		else {

			if(dx!=dy && (!it[dx] || !it[dy])) {

				if(it[dy]) swap(dx,dy);

				ata[dy]=dx;

				es.pb({x,y});

				ans+=c;

			}

		}

	}

	printf("%lld\n",ans);

	printf("%d\n",sz(stat));

	for(int i:stat) printf("%d ",i);

	printf("\n%d\n",sz(es));

	for(auto i:es) printf("%d %d\n",i.st,i.nd);

}