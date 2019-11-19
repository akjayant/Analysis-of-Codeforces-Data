#include <bits/stdc++.h>
#define ll long long
#define all(a) (a).begin(), (a).end()
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define sz() size()
#define fr first
#define sc second
#define pb push_back
#define er erase
#define in insert
#define pi pair<int,int>
#define pii pair<pair<int,int>,int>
#define mp make_pair
#define int long long
#define rc(s) return cout<<s,0
#define rcc(s) cout<<s,exit(0)
///#define cin fin
///#define cout fout
using namespace std;



int n,u,v,par[2005],siz[2005],pus[2005];
pair<int,int>arr[2005];
int a[2005],b[2005],dp[20015],curr[2005],rs,x;
vector<pair<int,pair<int,int>>>vecc;
vector<pair<int,int>>vec[2005],ans2;
vector<int>ans1;

int fin(int x){
	if(par[x]==x)return x;
	return par[x]=fin(par[x]);
}

void unire(int a1,int a2,int a3){
	int tz1=a1,tz2=a2;
	a1=fin(a1);
	a2=fin(a2);
	if(a1==a2) return;
	if(siz[a1]<siz[a2])swap(a1,a2);
	if((min(dp[a1],dp[a2])+a3+curr[a1]+curr[a2])<=(dp[a1]+dp[a2]+curr[a1]+curr[a2])){
		par[a2]=a1;
		siz[a1]+=siz[a2];
		dp[a1]=min(dp[a1],dp[a2]);
		if(dp[a1]==dp[a2]) pus[a1]=pus[a2];
		curr[a1]+=curr[a2]+a3,curr[a2]=0;
		for(int i=0;i<vec[a2].size();i++) vec[a1].push_back(vec[a2][i]);
		vec[a1].pb({tz1,tz2});
		vec[a2].clear();
	}
}
int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> arr[i].fr >> arr[i].sc;
	}
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) cin >> b[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			x=abs(arr[i].fr-arr[j].fr)+abs(arr[i].sc-arr[j].sc);
			x*=(b[i]+b[j]);
			vecc.pb({x,{i,j}});
		}
	}
	sort(all(vecc));
	for(int i=1;i<=n;i++) par[i]=i,siz[i]=1;
	for(int i=1;i<=n;i++){
		dp[i]=a[i],pus[i]=i,curr[i]=0;
	}
	for(int i=0;i<vecc.size();i++){
		v=vecc[i].sc.fr,u=vecc[i].sc.sc;
		x=vecc[i].fr;
		unire(v,u,x);
	}
	for(int i=1;i<=n;i++){
		if(fin(i)!=i)continue;
		else{
            rs+=curr[i]+dp[i];
            ans1.push_back(pus[i]);
            for(int j=0;j<vec[i].size();j++) ans2.push_back(vec[i][j]);
		}
	}
	cout << rs << '\n' << ans1.size();
	cout << '\n';
	for(int i=0;i<ans1.size();i++) cout << ans1[i] << ' ';
	cout << '\n';
	cout << ans2.size() << '\n';
	for(int i=0;i<ans2.size();i++) cout << ans2[i].fr << ' ' << ans2[i].sc << '\n';
}
