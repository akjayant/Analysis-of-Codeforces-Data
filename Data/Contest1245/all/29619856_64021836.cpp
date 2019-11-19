#include<bits/stdc++.h>
#define ll long long 
#define pii pair<int,int>
#define fi first
#define se second
#define MP make_pair
using namespace std;
const int maxn = 2005;
ll mpt[2005][2005];
int x[maxn],y[maxn];
int c[maxn],k[maxn];
int n;
ll DIS(int i,int j){
	return abs(x[i]-x[j])+abs(y[i]-y[j]);
}
vector<int>ans1;
vector<pii>ans2;
ll ans;
ll dis[maxn];
int vis[maxn];
int zero[maxn];
void prim(){
	for(int i=1;i<=n;i++){
		dis[i]=mpt[0][i];
	}
	for(int i=1;i<=n;i++){
		int p;
		ll maxx=-1;
		for(int j=1;j<=n;j++){
			if(vis[j])continue;
			if(maxx==-1||maxx>dis[j]){
				p = j;
				maxx = dis[j];
			}
		}
		vis[p]=1;ans+=maxx;
		if(!zero[p])ans1.push_back(p);
		else ans2.push_back(MP(zero[p],p));
		for(int j=1;j<=n;j++){
			if(vis[j])continue;
			if(mpt[p][j]<dis[j]){
				dis[j]=mpt[p][j];
				zero[j]=p;
			}
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d%d",x+i,y+i);
	}
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)scanf("%d",&k[i]);
	for(int i=1;i<=n;i++){
		mpt[0][i]=mpt[i][0]=c[i];
		for(int j=i+1;j<=n;j++){
			mpt[i][j]=mpt[j][i]=(ll)DIS(i,j)*(k[i]+k[j]);
		}
	}
	prim();
	cout<<ans<<endl;
	cout<<ans1.size()<<endl;
	for(auto v:ans1){
		cout<<v<<" ";
	}
	puts("");
	cout<<ans2.size()<<endl;
	for(auto v:ans2){
		cout<<v.fi<<" "<<v.se<<endl;
	}
	return 0;
}