#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
typedef long long LL;
const int N=2000006;
LL n,k,lm[N],a[N],P[N],Q[N],ans;
bool vis[2][N];
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>k;
	if(k<n*(n+1)/2){
		cout<<-1<<endl;
		return 0;
	}
	for(int i=1;i<=n;++i)
		a[i]=i;
	for(int i=n,tmp=n;i>=1;i-=2,--tmp)
		lm[i]=lm[i-1]=tmp;
	LL now=n*(n+1)/2,pos;
	for(int i=n;i;--i){
		LL tmp=a[i];
		if(now<k)
			a[i]+=min(lm[i]-a[i],k-now);
		now+=min(lm[i]-tmp,k-now);
	}
	for(int i=1;i<=n;++i)
		if(a[i]==a[i-1])
			Q[i]=a[i],vis[1][a[i]]=true;
		else
			P[i]=a[i],vis[0][a[i]]=true;
	LL p1=1,p2=1;
	for(int i=1;i<=n;++i){
		while(vis[0][p1])
			++p1;
		while(vis[1][p2])
			++p2;
		if(!P[i])
			P[i]=p1,++p1;
		if(!Q[i])
			Q[i]=p2,++p2;
		ans+=max(P[i],Q[i]);
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;++i)
		cout<<P[i]<<" ";
	cout<<endl;
	for(int i=1;i<=n;++i)
		cout<<Q[i]<<" ";
	return 0;
}
