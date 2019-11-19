/*#include<iostream>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdio>
#include<stack>
#include<map>
#include<queue>
#include<vector>*/
/*
lower_bound是大于等于
upper_bound是大于
set存元素
map有映射
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=100010;

int c[MAXN][4]={0};
int N;
int g[MAXN]={0};
int col[MAXN]={0};
int ac[MAXN]={0};
int S;
int a[4]={0};
vector<int> p[MAXN];
ll Ans=0;
ll Cnt=0;

void dfs(int u,int fa,int dep){
	int v;
	int tmp;
	tmp=dep%3;
	if(tmp==0) tmp=3;
	Cnt+=c[u][a[tmp]];
	col[u]=a[tmp];
	
	if(dep==N){
		if(Cnt<Ans){
			Ans=Cnt;
			for(int i=1;i<=N;i++){
				ac[i]=col[i];
			}
		}
	}
	
	for(int i=0;i<p[u].size();i++){
		v=p[u][i];if(v==fa) continue;
		dfs(v,u,dep+1);
	}
	
	Cnt-=c[u][a[tmp]];
}

void prepare(){
	Ans=10000000000000000;
	cin>>N;
	for(int i=1;i<=N;i++){
		scanf("%d",&c[i][1]);
	}
	for(int i=1;i<=N;i++){
		scanf("%d",&c[i][2]);
	}
	for(int i=1;i<=N;i++){
		scanf("%d",&c[i][3]);
	}
	int x,y; 
	for(int i=1;i<=N-1;i++){
		scanf("%d %d",&x,&y);
		g[x]++;
		g[y]++;
		p[x].push_back(y);
		p[y].push_back(x);
	}
	int flag=0;
	for(int i=1;i<=N;i++){
		if(g[i]>=3) flag=1;
		if(g[i]==1) S=i;
	}
	if(flag){
		cout<<-1<<endl;
		return; 
	}
	else{
		a[1]=1;a[2]=2;a[3]=3;
		dfs(S,S,1);
		a[1]=1;a[2]=3;a[3]=2;
		dfs(S,S,1);
		a[1]=2;a[2]=1;a[3]=3;
		dfs(S,S,1);
		a[1]=2;a[2]=3;a[3]=1;
		dfs(S,S,1);
		a[1]=3;a[2]=1;a[3]=2;
		dfs(S,S,1);
		a[1]=3;a[2]=2;a[3]=1;
		dfs(S,S,1);
	}
	cout<<Ans<<endl;
	for(int i=1;i<=N;i++){
		printf("%d ",ac[i]);
	}
}

void solve(){

}

int main(){
	prepare();
	solve();
	return 0;
}
