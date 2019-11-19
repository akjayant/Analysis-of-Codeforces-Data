#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize ("-ffloat-store") // to restrict undesirable precision
#pragma GCC optimize ("-fno-defer-pop")// to pop argument of function as soon as it returns
#define all(a) a.begin(),a.end()
#define ll long long int
#define ld long double
ll power(ll a,ll b,ll m){ if(b==0) return 1; if(b==1) return a%m; ll t=power(a,b/2,m)%m; t=(t*t)%m; if(b&1) t=((t%m)*(a%m))%m; return t;}
ll modInverse(ll a, ll m) { return power(a, m-2, m); }
#define ps push_back
#define fs first
#define takeline cin.ignore();
#define sc second
#define N 3000005
#define endl "\n"
#define mod 1000000007
//((1.0l)*BIG MULTIPLY MAGIC?)
// string to integer stoi()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();
//-----------------------------------------------
ll n,an=0,mn=1e18; ll c1[N],c2[N],c3[N],fl[N],cl[N]; vector<ll> vc[N];
void dfs(ll i,ll par,ll gp){
	fl[i]=1;

	ll cur=1;
	if(cl[par]==cur||cl[gp]==cur) cur++;
	if(cl[par]==cur||cl[gp]==cur) cur++;
	cl[i]=cur;
	if(cur==1) an+=c1[i];
	else if(cur==2) an+=c2[i];
	else an+=c3[i];
	for(auto it:vc[i]){
		if(fl[it]) continue;	
		dfs(it,i,par);
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll i,j,k,l;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>c1[i];
	}
	for(i=1;i<=n;i++){
		cin>>c2[i];
	}
	for(i=1;i<=n;i++){
		cin>>c3[i];
	}

	for(i=1;i<n;i++){
		cin>>k>>l;
		vc[k].ps(l);
		vc[l].ps(k);
	}

	ll x=-1;
	for(i=1;i<=n;i++){
		if(vc[i].size()>2){
			cout<<"-1";return 0;
		}
		if(vc[i].size()==1){
			if(x==-1) x=i;
		}
	}
	//cout<<x<<" "<<vc[x][0]<<endl;
	ll a1,a2;
	cl[x]=1;
	cl[vc[x][0]]=2; an=c1[x]+c2[vc[x][0]];
	fl[x]=1; fl[vc[x][0]]=1;
	for(auto it:vc[vc[x][0]]){
		if(it==x) continue;
		dfs(it,vc[x][0],x);
	}
	if(an<mn){
		mn=an;
		a1=1; a2=2;
	}

	cl[x]=1; an=0; memset(fl,0,sizeof(fl));
	cl[vc[x][0]]=3; an=c1[x]+c3[vc[x][0]];
	fl[x]=1; fl[vc[x][0]]=1;
	for(auto it:vc[vc[x][0]]){
		if(it==x) continue;
		dfs(it,vc[x][0],x);
	}
	if(an<mn){
		mn=an;
		a1=1; a2=3;
	}
	
	cl[x]=2; an=0; memset(fl,0,sizeof(fl));
	cl[vc[x][0]]=1; an=c2[x]+c1[vc[x][0]];
	fl[x]=1; fl[vc[x][0]]=1;
	for(auto it:vc[vc[x][0]]){
		if(it==x) continue;
		dfs(it,vc[x][0],x);
	}
	if(an<mn){
		mn=an;
		a1=2; a2=1;
	}

	cl[x]=2; an=0; memset(fl,0,sizeof(fl));
	cl[vc[x][0]]=3; an=c2[x]+c3[vc[x][0]];
	fl[x]=1; fl[vc[x][0]]=1;
	for(auto it:vc[vc[x][0]]){
		if(it==x) continue;
		dfs(it,vc[x][0],x);
	}
	if(an<mn){
		mn=an;
		a1=2; a2=3;
	}

	cl[x]=3; an=0; memset(fl,0,sizeof(fl));
	cl[vc[x][0]]=1; an=c3[x]+c1[vc[x][0]];
	fl[x]=1; fl[vc[x][0]]=1;
	for(auto it:vc[vc[x][0]]){
		if(it==x) continue;
		dfs(it,vc[x][0],x);
	}
	if(an<mn){
		mn=an;
		a1=3; a2=1;
	}

	cl[x]=3; an=0; memset(fl,0,sizeof(fl));
	cl[vc[x][0]]=2; an=c3[x]+c2[vc[x][0]];
	fl[x]=1; fl[vc[x][0]]=1;
	for(auto it:vc[vc[x][0]]){
		if(it==x) continue;
		dfs(it,vc[x][0],x);
	}
	if(an<mn){
		mn=an;
		a1=3; a2=2;
	}

	cout<<mn<<endl;
	cl[x]=a1; an=0; memset(fl,0,sizeof(fl));
	cl[vc[x][0]]=a2; 
	fl[x]=1; fl[vc[x][0]]=1;
	for(auto it:vc[vc[x][0]]){
		if(it==x) continue;
		dfs(it,vc[x][0],x);
	}
	for(i=1;i<=n;i++){
		cout<<cl[i]<<" ";
	}
	return 0;
}
