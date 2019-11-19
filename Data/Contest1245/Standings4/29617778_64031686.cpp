// (^_^) (^_^) (^_^) (^_^)
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define mp make_pair
#define vi vector<ll>
#define vii vector<vi>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define fi first
#define se second
#define mod LLONG_MAX
#define all(x) (x).begin(),(x).end()
#define tr(c,it) for(auto it=(c).begin();it!=(c).end();it++)
#define pre(c,x) ((c).find(x) != (c).end())
#define cpre(c,x) (find(all(c),x) != (c).end())
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define rep(i,a,b)	for(int i=a;i<b;i++)
#define repr(i,a,b) for(int i=a;i>b;i--)
vi par(2001,0);
vi sz(2001,1);
ll val[2001];
ll con[2001];
int blb[2001];
void in(int n){
   for(int i=1;i<=n;i++){
   		par[i]=i;
   		sz[i]=1;
   		blb[i]=i;
   	}
}
int root(int i){
	if(par[i]!=i)
	par[i]=root(par[i]);
	return par[i];
}
vector<pii>prt;
void un(ll temp,int x,int y){
	int r_x=root(x);
	int r_y=root(y);
	if(r_x==r_y)
	return;//mandatory
	if(sz[r_x]<sz[r_y])
	swap(r_x,r_y);
	
	int x1=blb[r_x],x2=blb[r_y];
	ll z1=val[x1]+con[r_x]+con[r_y]+temp;
	ll z2=val[x2]+con[r_x]+con[r_y]+temp;
	ll np=val[x1]+val[x2]+con[r_x]+con[r_y];
	if(np<=z1 && np<=z2)
	return;
	if(z1<z2){
		con[r_x]=con[r_x]+con[r_y]+temp;
		blb[r_x]=x1;
	}
	else{
		con[r_x]=con[r_x]+con[r_y]+temp;
		blb[r_x]=x2;
	}
	prt.pb(mp(x,y));
	par[r_y]=r_x;
	sz[r_x]+=sz[r_y];
}
vector< pair< ll, pii > >ss;
int main(){
	int n;
	cin>>n;
	in(n);
	vector<pii>e(n+1);
	
	for(int i=1;i<=n;i++){
		cin>>e[i].fi>>e[i].se;
	}
	for(int i=1;i<=n;i++){
		cin>>val[i];
	}
	ll temp[n+1];
	for(int i=1;i<=n;i++)
	cin>>temp[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ss.pb(mp((temp[i]+temp[j])*(abs(e[i].fi-e[j].fi)+abs(e[i].se-e[j].se)),mp(i,j)));
		}
	}
	sort(ss.begin(),ss.end());
	for(int i=0;i<ss.size();i++){
		un(ss[i].fi,ss[i].se.fi,ss[i].se.se);
	}
	ll ress=0;
	vector<int> dd;
	for(int i=1;i<=n;i++){
		if(par[i]==i){
			ress+=con[i];
			ress+=val[blb[i]];
			dd.pb(blb[i]);
		}
	}
	cout<<ress<<endl;
	cout<<dd.size()<<endl;
	for(int i=0;i<dd.size();i++)
	cout<<dd[i]<<endl;
	cout<<prt.size()<<endl;
	for(int i=0;i<prt.size();i++){
		cout<<prt[i].fi<<" "<<prt[i].se<<endl;
	}
	return 0;
}

















