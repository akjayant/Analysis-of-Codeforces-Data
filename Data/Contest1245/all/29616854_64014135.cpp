#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#include <deque>
#include <stack>
#include <bitset>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
#define rep(i,n) for (int i=0;i<n;++i)
#define REP(i,n) for (int i=1;i<=n;++i)
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define read(x) scanf("%d",&x)
typedef pair<ll,pii> info;
int n;
ll x[2005],y[2005],c[2005],k[2005];
vector<int> V;
vector<pii> E;
ll ans=0;
priority_queue<info,vector<info>,greater<info>> pq;
bool vis[2005];
inline ll dist(int uu,int vv){
	return abs(x[uu]-x[vv])+abs(y[uu]-y[vv]);
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	REP(i,n) cin>>x[i]>>y[i];
	REP(i,n) cin>>c[i];
	REP(i,n) cin>>k[i];
	int minC=1e9+7,minPos=0;
	REP(i,n) if (c[i]<minC){
		minC=c[i];minPos=i;
	}
	V.push_back(minPos);
	ans=minC;
	vis[minPos]=1;
	REP(i,n) if (i!=minPos){
		if (c[i]<(k[i]+k[minPos])*dist(i,minPos))pq.push(mp(c[i],mp(i,0)));
		else pq.push(mp((k[i]+k[minPos])*dist(i,minPos),mp(i,minPos)));
	}
	int cnt=1;
	while(cnt<n&&!pq.empty()){
		while(!pq.empty()&&vis[pq.top().S.F]) pq.pop();
		if (pq.empty()) break;
		info tmp=pq.top();pq.pop();
		ans+=tmp.F;
		int u=tmp.S.F;int way=tmp.S.S;
		vis[u]=1;++cnt;
		if (way==0) V.push_back(u);
		else E.push_back(mp(u,way));
		if (cnt==n) break;
		for (int i=1;i<=n;++i) if (!vis[i]) {
			if ((k[i]+k[u])*dist(i,u)<c[i]) pq.push(mp((k[i]+k[u])*dist(i,u),mp(i,u)));
		}
	}
	cout<<ans<<endl;
	cout<<V.size()<<endl;
	for (int i=0;i<V.size();++i) cout<<V[i]<<' ';
	cout<<endl;
	cout<<E.size()<<endl;
	for (int i=0;i<E.size();++i) cout<<E[i].F<<' '<<E[i].S<<endl;
	return 0;
}