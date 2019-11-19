#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define inf 0x3f3f3f3f
#define inff 0x3f3f3f3f3f3f3f3f
#define ll long long
#define ull unsigned long long
#define sscc ios::sync_with_stdio(false);cin.tie(0);
#define ms(a) memset(a,0,sizeof(a))
#define mss(a) memset(a,-1,sizeof(a))
#define msi(a) memset(a,inf,sizeof(a))
using namespace std;

struct node{
	ll x,y,w,f;
	bool operator <(node B){
		return w<B.w;
	}
};
struct A{
	ll x,y;
};

A a[2005];
ll s[2005];
ll vis[2005];
vector<node> v;
vector<node> f1;
vector<node> f2;

ll findd(ll x){
	return vis[x]==x?x:vis[x]=findd(vis[x]);
}

int main()
{
	sscc;
	ll n;
	cin>>n;
	for(ll i=0;i<=n+1;i++)	vis[i]=i;
	ll T=n+1;
	for(ll i=1;i<=n;i++){
		ll x,y;
		cin>>x>>y;
		a[i]={x,y};
	}
	for(ll i=1;i<=n;i++){
		ll w;
		cin>>w;
		v.push_back({T,i,w,0});
	}
	for(ll i=1;i<=n;i++){
		cin>>s[i];
	}
	for(ll i=1;i<=n;i++){
		ll x1=a[i].x,y1=a[i].y;
		for(ll j=i+1;j<=n;j++){
			ll x2=a[j].x,y2=a[j].y;
			ll w=(s[i]+s[j])*(abs(x1-x2)+abs(y1-y2));
			v.push_back({i,j,w,1});
		}
	}
	sort(v.begin(),v.end());
	ll ans=0;
	for(auto re:v){
		ll x=findd(re.x);
		ll y=findd(re.y);
		if(x!=y){
			vis[x]=y;
			ans+=re.w;
			if(re.f==0){
				f1.push_back(re);
			}else{
				f2.push_back(re);	
			}
		}
	}
	printf("%lld\n",ans);
	printf("%d\n",(int)f1.size());
	for(auto re:f1){
		printf("%lld ",re.y);
	}
	printf("\n");
	printf("%d\n",(int)f2.size());
	for(auto re:f2){
		printf("%lld %lld\n",re.x,re.y);
	}
	return 0;
}

