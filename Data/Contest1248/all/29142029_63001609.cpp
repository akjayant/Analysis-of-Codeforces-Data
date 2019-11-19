#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <ctime>
#include <cmath>
#define ll long long
#define N 11000
#define inf 0x7FFFFFF
using namespace std;
int summ,n,sum[N],min1[N],min2[N];
char s[N];
inline bool check(int s){
	if(min2[s]-sum[s-1]<0) return false;
	if(min1[s-1]+sum[n]-sum[s-1]<0) return false;
	return true;
}
inline void work(int ss){
	int yu=0,tot=0;
	for(int i=ss;i!=(ss==1?n:ss-1);i=(i+1>n?1:i+1)){
		if(tot==0) ++yu;
		if(s[i]=='(') ++tot;
		else --tot;
	}
	summ=yu;
}
int main(){
//	freopen("a.in","r",stdin);
	scanf("%d",&n);
	scanf("%s",s+1);
	int ans=0,x=1,y=1;
	sum[0]=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='(') sum[i]=sum[i-1]+1;
		else sum[i]=sum[i-1]-1;
	}
	
	if(sum[n]==0){
		for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j){
			swap(s[i],s[j]);
			sum[0]=0;
			for(int ii=1;ii<=n;++ii){
				if(s[ii]=='(') sum[ii]=sum[ii-1]+1;
				else sum[ii]=sum[ii-1]-1;
			}
			min1[0]=inf;
			for(int ii=1;ii<=n;++ii) min1[ii]=min(min1[ii-1],sum[ii]);
			min1[n+1]=inf;
			for(int ii=n;ii>=1;--ii) min2[ii]=min(min2[ii+1],sum[ii]);
			
			for(int st=1;st<=n;++st){
				if(check(st)){
					summ=0;
					work(st);
					if(summ>ans) ans=summ,x=i,y=j;
					break;
				}
			}
			swap(s[i],s[j]);
		}
	
	
	} 
	
	printf("%d\n%d %d\n",ans,x,y);
	return 0;
}
