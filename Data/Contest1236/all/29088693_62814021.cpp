#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
const int maxn=100050;
struct point{
	int x,y;
	point(int x=0,int y=0):x(x),y(y){}
};
vector<int> p1[maxn],p2[maxn];
point p[maxn],_p[maxn*10];
int n,m,k,tot;

int cmp1(point a,point b){
	return a.x<b.x||a.x==b.x&&a.y<b.y;
}
int cmp2(point a,point b){
	return a.y<b.y||a.y==b.y&&a.x<b.x;
}

void solve(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=k;i++){
		scanf("%d %d",&p[i].x,&p[i].y);
	}
	sort(p+1,p+k+1,cmp1);
	for(int i=1;i<=n;i++)	p1[i].push_back(0);
	for(int i=1;i<=n;i++)	p1[i].push_back(0);
	for(int i=1;i<=k;i++)	p1[p[i].x].push_back(p[i].y);
	for(int i=1;i<=n;i++)	p1[i].push_back(m+1);
	for(int i=1;i<=n;i++)	p1[i].push_back(m+1);
	sort(p+1,p+k+1,cmp2);
	for(int i=1;i<=m;i++)	p2[i].push_back(0);
	for(int i=1;i<=m;i++)	p2[i].push_back(0);
	for(int i=1;i<=k;i++)	p2[p[i].y].push_back(p[i].x);	
	for(int i=1;i<=m;i++)	p2[i].push_back(n+1);
	for(int i=1;i<=m;i++)	p2[i].push_back(n+1);
	ll sum=(ll)n*m-k,last=0,res=1;
	int u=0,d=n+1,l=0,r=m+1,flag=1;
	int x0=1,y0=1;
	while(1){
		int nx=x0,ny=y0;
		if(flag==1){
			ny=min(r,*upper_bound(p1[x0].begin(),p1[x0].end(),y0))-1;
			res+=ny-y0;y0=ny;u=x0;
		}
		else if(flag==2){
			nx=min(d,*upper_bound(p2[y0].begin(),p2[y0].end(),x0))-1;
			res+=nx-x0;x0=nx;r=y0;
		}
		else if(flag==3){
			ny=max(l,*(lower_bound(p1[x0].begin(),p1[x0].end(),y0)-1))+1;
			res+=y0-ny;y0=ny;d=x0;
		}
		else if(flag==4){
			nx=max(u,*(lower_bound(p2[y0].begin(),p2[y0].end(),x0)-1))+1;
			res+=x0-nx;x0=nx;l=y0;
		}
		if(res==last)	break;
		flag=flag%4+1;
		last=res;
	}
	printf("%s\n",sum==res?"YES":"NO");
}
int main(){
	solve();
	return 0;
}