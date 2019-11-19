#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repp(i,a) for(int i=1;i<=a;i++)
#define eb emplace_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define Fi first
#define Se second
#define INF 987654321
#define IINF 987654321987654321
#define LINF 987654321987654321
//0x3F3F3F3F3F3F3F3Fll
#define sz(v) ((int)((v).size()))
#define all(v) v.begin(),v.end()
#define pq priority_queue
#define BIGMOD 9223372036854775783
#define PI 3.14159265358979
#define eps 1e-7
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<bool,bool> pbb;
typedef pair<ll,ll> pll;
typedef complex<double> base;
typedef pair<bool,int> pbi;
typedef pair<ll,int> pli;
typedef pair<pll,ll> plll;
const ll MOD=1e9+7;
int n,m,k;
vector<int> x[100004],y[100004];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,0,k){
		int ss,dd;
		scanf("%d%d",&ss,&dd);
		x[ss].pb(dd);
		y[dd].pb(ss);
	}
	rep(i,0,n+1) sort(all(x[i]));
	rep(j,0,m+1) sort(all(y[j]));
	int dir=0;
	int nx=1,ny=1;
	int MX=n,mx=1,MY=m,my=1;
	int cnt=0;
	k=n*m-k-1;
	while(k){
		cnt++;
		if(cnt>2*100002){
			printf("No\n");
			return 0;
		}
		if(mx>MX||my>MY){
			printf("No\n");return 0;
		}
		if(dir==0){
			auto it=lower_bound(all(x[nx]),ny);
			int J;
			if(it==x[nx].end()) {
				J=MY;
			}
			else J=min((*it)-1,MY);
			k-=J-ny;
			ny=J;
			mx=nx+1;
			MY=ny;
		}
		else if(dir==1){
			auto it=lower_bound(all(y[ny]),nx);
			int J;
			if(it==y[ny].end()) J=MX;
			else J=min((*it)-1,MX);
			k-=J-nx;
			nx=J;
			MY=ny-1;
			MX=nx;
		}
		else if(dir==2){
			auto it=upper_bound(all(x[nx]),ny);
			int J;
			if(it==x[nx].begin()) J=my; 
			else {
				it--;
				J=max((*it)+1,my);
			}
			k-=ny-J;
			ny=J;
			MX=nx-1;
			my=ny;
			//printf("@%d %d %d %d %d@",MX,MY,mx,my,k);
		}
		else if(dir==3){
			auto it=upper_bound(all(y[ny]),nx);
			int J;
			if(it==y[ny].begin()) J=mx; 
			else {
				it--;
				J=max((*it)+1,mx);
			}
			k-=nx-J;
			nx=J;
			my=ny+1;
			mx=nx;
		}
		
		//printf("!%d!",k);
		dir=(dir+1)%4;
	}
	printf("Yes\n");
}
