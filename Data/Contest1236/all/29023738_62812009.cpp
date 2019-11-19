#include<cstdio>
#include<vector>
#include<algorithm>
using std::lower_bound;
using std::upper_bound;
using std::min;
using std::max;
using std::vector;
using std::sort;
typedef long long ll;
const int N=1e5+5;
vector<int>ax[N],ay[N];
int bx[4]={0,1,0,-1},by[4]={1,0,-1};
int main(){
	int n,m,k,x,y,f=0,lx=1,ly=0,rx,ry,t;
	ll ans;
	scanf("%d%d%d",&n,&m,&k);rx=n+1,ry=m+1;
	ans=(ll)n*m-k-1; 
	for(int i=1;i<=n;++i) ax[i].push_back(0);
	for(int i=1;i<=m;++i) ay[i].push_back(0);
	for(int i=1;i<=k;++i){
		scanf("%d%d",&x,&y);
		ax[x].push_back(y);
		ay[y].push_back(x);
	}
	for(int i=1;i<=n;++i){
		sort(ax[i].begin(),ax[i].end());
		ax[i].push_back(m+1);
	}
	for(int i=1;i<=m;++i){
		sort(ay[i].begin(),ay[i].end());
		ay[i].push_back(n+1);
	}
	for(x=y=1;lx<rx&&ly<ry;f=(f+1)%4){
		if(!f){
			t=ax[x][upper_bound(ax[x].begin(),ax[x].end(),y)-ax[x].begin()];
			ry=min(t-1,ry-1);
			ans-=ry-y;
			y=ry;
		}
		else if(f==1){
			t=ay[y][upper_bound(ay[y].begin(),ay[y].end(),x)-ay[y].begin()];
			rx=min(t-1,rx-1);
			ans-=rx-x;
			x=rx;
		}
		else if(f==2){
			t=ax[x][lower_bound(ax[x].begin(),ax[x].end(),y)-ax[x].begin()-1];
			ly=max(t+1,ly+1);
			ans-=y-ly;
			y=ly;
		}
		else{
			t=ay[y][lower_bound(ay[y].begin(),ay[y].end(),x)-ay[y].begin()-1];
			lx=max(t+1,lx+1);
			ans-=x-lx;
			x=lx;
		}
	}
	ans?printf("No"):printf("Yes");
	return 0;
}