 
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
 
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long
 
using namespace std;
 
 
using namespace std;
void file(){
	#ifndef ONLINE_JUDGE
    	freopen("tst.txt", "r", stdin);
	#endif	
}
int tc;
const int N=1e6+5,MOD=1e9+7;
int n;

ll cost[2005][2005];
int main()
{	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 	file();

 	scanf("%d",&n);

 	vector<pair<int,int>>a(n);
 	std::vector<int> c(n),k(n);
 	for(int i=0;i<n;i++){
 		scanf("%d %d",&a[i].first,&a[i].second);
 	}

 	for(int i=0;i<n;i++)scanf("%d",&c[i]);
 	for(int i=0;i<n;i++)scanf("%d",&k[i]);

 	for(int i=0;i<n;i++){
 		for(int j=0;j<n;j++){
 			cost[i][j]=(ll)(k[i]+k[j])*(abs(a[i].first-a[j].first)+abs(a[i].second-a[j].second));
 		}
 	}

 	priority_queue<pair<ll,pair<int,int>>,vector<pair<ll,pair<int,int>>>,greater<pair<ll,pair<int,int>>>>q;
 	ll ans = 0;
 	for(int i=0;i<n;i++){
 		q.push({c[i],{i,-1}});
 	}
 	std::vector<bool> vis(n);
 	std::vector<int> ans1;
 	std::vector<pair<int,int>> ans2;
 	while(sz(ans1)+sz(ans2)<n){
 		pair<ll,pair<int,int>> p = q.top();
 		q.pop();

 		int u = p.second.first , v = p.second.second; 
 		ll cst = p.first;
 		if(vis[u])continue;
 		vis[u]=true;
 		ans+=cst;
 		if(v==-1){
 			ans1.pb(u);
 		}
 		else 	ans2.pb({u,v});
 		for(int i=0;i<n;i++){
 			if(vis[i])continue;
 			q.push({cost[u][i],{i,u}});
 		}
 	}

 	printf("%lld\n",ans );
 	printf("%d\n",sz(ans1));

 	for(auto x : ans1)printf("%d ",x+1 );

 	printf("\n%d\n",sz(ans2));

 	for(auto p : ans2){
 		printf("%d %d\n",p.first+1,p.second+1);
 	}

}