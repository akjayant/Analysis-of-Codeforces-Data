#include<stdio.h>
#include<queue>
#include<stack>
std::stack<int>a1;
std::stack<std::pair<int,int> >a2;
int f[2002],n,p[2002][2],k[2002];long long ans=0;
inline int gf(int p){return f[p]==p?p:(f[p]=gf(f[p]));}
inline int Abs(int p){return p<0?-p:p;}
std::priority_queue<std::pair<long long,std::pair<int,int> > >Q;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&p[i][0],&p[i][1]),f[i]=i;
	for(int i=1;i<=n;i++)scanf("%d",&k[0]),Q.push(std::make_pair(-(long long)k[0],std::make_pair(0,i)));
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<i;j++){
			Q.push(std::make_pair(-1ll*(k[i]+k[j])*(Abs(p[i][0]-p[j][0])+Abs(p[i][1]-p[j][1])),std::make_pair(i,j)));
		}
	}while(!Q.empty()){
		long long l=-Q.top().first;
		int g=Q.top().second.first,h=Q.top().second.second;
		int p=gf(g),q=gf(h);
		if(p!=q){
			f[p]=q,ans+=l;
			if(g==0)a1.push(h);
			else if(h==0)a1.push(g);
			else a2.push(std::make_pair(g,h));
		}
		Q.pop();
	}printf("%lld\n%d\n",ans,a1.size());
	while(!a1.empty())printf("%d ",a1.top()),a1.pop();
	printf("\n%d\n",a2.size());
	while(!a2.empty())printf("%d %d\n",a2.top().first,a2.top().second),a2.pop();
}