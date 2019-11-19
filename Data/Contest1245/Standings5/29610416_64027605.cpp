#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define fi first
#define se second
#define MAXN 100005
struct T{
	ll x,y,c,k,id;
}a[MAXN];
inline bool cmp(T a,T b){
	return a.c<b.c;
}
inline ll cost(T a,T b){
	return (labs(a.x-b.x)+labs(a.y-b.y))*(a.k+b.k);
}
int vis[MAXN];
vector<pii> conn;
vector<ll> create;
priority_queue<pii,vector<pii>,greater<pii> > q;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i].x>>a[i].y,a[i].id=i;
	for(int i=1;i<=n;i++)	cin>>a[i].c;
	for(int i=1;i<=n;i++)	cin>>a[i].k;
	for(int i=1;i<=n;i++)	q.push({a[i].c,i});
	ll ans=0;
	for(int i=1;i<=n;i++){
		pii x=q.top(); q.pop();
		while(vis[x.se]){
			x=q.top();	q.pop();
		}
		ans+=x.fi;
		vis[x.se]=1;
		if(x.fi==a[x.se].c)	create.push_back(x.se);
		else{
			ll r;
			for(int i=1;i<=n;i++)
				if(vis[i]&&cost(a[i],a[x.se])==x.fi){
					r=i;break;
				}
			conn.push_back({x.se,r});
		}
		for(int i=1;i<=n;i++)
			if(i!=x.se&&!vis[i])	q.push({cost(a[x.se],a[i]),i});
	}
	cout<<ans<<endl;
	cout<<create.size()<<endl;
	sort(create.begin(),create.end());
	for(auto &x:create)	cout<<x<<" ";
	cout<<endl;
	cout<<conn.size()<<endl;
	for(auto &x:conn)	cout<<x.fi<<" "<<x.se<<endl;
	return 0;
}
