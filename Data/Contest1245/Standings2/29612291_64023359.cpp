#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const long long mx=1e9;
const long long mod=1e9+7;
const long long maxn=2e5+10;
long long n,x[maxn],y[maxn],c[maxn],k[maxn],root[maxn];
long long ans1[maxn],ans2[maxn][2],c1,c2,ans;
struct ooo{
	long long x,y,w;
}now;
bool operator<(const ooo&a,const ooo& b){
	if(a.w!=b.w)
		return a.w>b.w;
	if(a.x!=b.x)
		return a.x<b.x;
	return a.y<b.y;
}
priority_queue<ooo> q;
long long f(long long x){
	if(root[x]==x)
		return x;
	root[x]=f(root[x]);
	return root[x];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		root[i]=i;
			
	}
	for(long long i=1;i<=n;i++){
		cin>>c[i];
			
	}
	for(long long i=1;i<=n;i++){
		cin>>k[i];		
	}
	for(long long i=1;i<=n;i++){
		now.x=0;
		now.y=i;
		now.w=c[i];
		q.push(now);
		for(long long j=1;j<i;j++){
			now.x=i;
			now.y=j;
			now.w=(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
			q.push(now);
		}
	}
	int cnt=0;
	while(!q.empty()&&cnt<n){
		now=q.top();
		q.pop();
		if(f(now.x)!=f(now.y)){
			cnt++;
			ans+=now.w;
			if(now.x==0){
				c1++;
				ans1[c1]=now.y;
			}else{
				c2++;
				ans2[c2][0]=now.x;
				ans2[c2][1]=now.y;
			}
			root[f(now.y)]=f(now.x);
		}
	}
	cout<<ans<<endl;
	cout<<c1<<endl;
	for(int i=1;i<=c1;i++)
		cout<<ans1[i]<<" ";
	cout<<endl<<c2<<endl;
	for(int i=1;i<=c2;i++)
		cout<<ans2[i][0]<<" "<<ans2[i][1]<<endl;
	return 0;
}