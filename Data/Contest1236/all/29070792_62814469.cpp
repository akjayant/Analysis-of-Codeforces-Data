#include<bits/stdc++.h>
#define ll long long
#define scan(x) scanf("%d",&x)
#define scanl(x) scanf("%I64d",&x)
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=1e5+5;
const int mod=1e9+7; 
int n;
int m,k;
vector<int> vx[maxn],vy[maxn];//vx为每行y值，vy为每列x值 
int l=0,r=m+1,t=0,b=n+1;
ll ans=0;
bool move(int x,int y,int d){
//	cout<<x<<" "<<y<<" "<<d<<" "<<ans<<"\n";
//	cout<<l<<" "<<r<<" "<<t<<" "<<b<<"\n";
	if(ans>k) return false;
	if(d==1){
		int p=upper_bound(vx[x].begin(),vx[x].end(),y)-vx[x].begin(),tt;
		if(p==vx[x].size()||vx[x][p]>=r) tt=r;
		else tt=vx[x][p];
		ans+=(r-tt)*1ll*(b-x);
		t=x;
		tt--;
		if(tt==y&&(x!=1||y!=1)) return ans==k;
		else if(tt==y&&x==1&&y==1) return move(x,y,2);
	//	else if(tt==y&&num==1) return move(x,tt,2);
		else return move(x,tt,2);
	}
	else if(d==2){
		int p=upper_bound(vy[y].begin(),vy[y].end(),x)-vy[y].begin(),tt;
		if(p==vy[y].size()||vy[y][p]>=b) tt=b;
		else tt=vy[y][p];
		ans+=(b-tt)*1ll*(y-l);
		r=y;
		tt--;
		if(tt==x) return ans==k;
	//	else if(tt==x&&num==1) return move(tt,y,3,2);
		else return move(tt,y,3);
	}
	else if(d==3){
		int p=lower_bound(vx[x].begin(),vx[x].end(),y)-vx[x].begin(),tt;
		p--;
		if(p<0||vx[x][p]<=l) tt=l;
		else tt=vx[x][p];
		ans+=(tt-l)*1ll*(x-t);
		b=x;
		tt++;
		if(tt==y) return ans==k;
		//else if(tt==y&&num==1) return move(x,tt,4,2);
		else return move(x,tt,4);
	}
	else{
		int p=lower_bound(vy[y].begin(),vy[y].end(),x)-vy[y].begin(),tt;
		p--;
		if(p<0||vy[y][p]<=t) tt=t;
		else tt=vy[y][p];
		ans+=(tt-t)*1ll*(r-y);
	//	cout<<ans<<"\n";
		l=y;
		tt++;
		if(tt==x) return ans==k;
	//	else if(tt==x&&num==1) return move(tt,y,1,2);
		else return move(tt,y,1);
	}
	return true;
}
int main(){
//	freopen("in.txt","r",stdin);
	scan(n);scan(m);scan(k);
	l=0,r=m+1,t=0,b=n+1;
	int x,y;
	for(int i=1;i<=k;i++){
		scan(x);scan(y);
		vx[x].push_back(y);
		vy[y].push_back(x);
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		sort(vx[i].begin(),vx[i].end());
	}
	for(int i=1;i<=m;i++){
		sort(vy[i].begin(),vy[i].end());
	}
	if(move(1,1,1)) cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}