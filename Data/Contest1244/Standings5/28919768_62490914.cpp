#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef complex<double> cp;

const int maxn=(int)2e5+9;
const ll mod=(ll)1e9+7;
const db pi=acos(-1);
const db eps=1e-15;

#define dbg(x) cerr<<#x<<" is "<<x<<endl;

int d[maxn];
vector<int> e[maxn];
int a[3][maxn];
int n;

void init(){
	scanf("%d",&n);
	for(int i=0;i<3;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j+1]);
		}
	}
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		e[a].push_back(b);
		e[b].push_back(a);
		d[a]++;
		d[b]++;
	}
}

ll ans;
int c[maxn];
int ttp[maxn];

void dfs(int u,int f,int ff){
	int tmp=c[f]|c[ff];
	c[u]=3-tmp;
	ans+=a[3-tmp][u];
	for(int x:e[u]){
		if(x!=f)dfs(x,u,f);
	}
}

void mv(){
	for(int i=1;i<=n;i++){
		ttp[i]=c[i];
	}
}

int main(){
	init();
	int e1=-1,e2=-1;
	for(int i=1;i<=n;i++){
		if(d[i]==1){
			if(e1<0){
				e1=i;
			}else{
				e2=i;
			}
		}
		if(d[i]>2){
			cout<<-1<<endl;
			return 0;
		}
	}
	ll mn;
	ans=0;
	c[maxn-1]=0;
	c[maxn-2]=1;
	dfs(e1,maxn-1,maxn-2);
	mn=ans;
	mv();
	ans=0;
	c[maxn-1]=1;
	c[maxn-2]=2;
	dfs(e1,maxn-1,maxn-2);
	if(ans<mn){
		mv();
		mn=ans;
	}
	ans=0;
	c[maxn-1]=0;
	c[maxn-2]=2;
	dfs(e1,maxn-1,maxn-2);
	if(ans<mn){
		mv();
		mn=ans;
	}
	ans=0;
	c[maxn-1]=1;
	c[maxn-2]=0;
	dfs(e1,maxn-1,maxn-2);
	if(ans<mn){
		mv();
		mn=ans;
	}
	ans=0;
	c[maxn-1]=2;
	c[maxn-2]=0;
	dfs(e1,maxn-1,maxn-2);
	if(ans<mn){
		mv();
		mn=ans;
	}
	ans=0;
	c[maxn-1]=2;
	c[maxn-2]=1;
	dfs(e1,maxn-1,maxn-2);
	if(ans<mn){
		mv();
		mn=ans;
	}
	cout<<mn<<endl;
	for(int i=1;i<=n;i++){
		printf("%d ",ttp[i]+1);
	}
	cout<<endl;
	return 0;
}

