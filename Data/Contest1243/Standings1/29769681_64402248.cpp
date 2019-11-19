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
const int MAXN=200010;

int N,M;
int vis[MAXN]={0};
vector<int> p[MAXN];
int fa[MAXN]={0};
int cnt=0;
int que[MAXN]={0};

int getfa(int x){
	if(fa[x]==x) return x;
	return fa[x]=getfa(fa[x]);
}

void merge(int x,int y){
	if(getfa(x)==getfa(y)) return;
	cnt--;
	fa[fa[x]]=fa[y];
}

void judge(int x){
	int pnt=0;
	sort(p[x].begin(),p[x].end());
	for(int i=1;i<=N;i++){
		if(pnt<p[x].size()&&p[x][pnt]==i){
			pnt++;
			continue;
		}
		merge(x,i);
		vis[i]=1;
	}
}

void prepare(){
	cin>>N>>M;
	cnt=N;
	for(int i=1;i<=N;i++) fa[i]=i;
	int x,y;
	for(int i=1;i<=M;i++){
		scanf("%d %d",&x,&y);
		p[x].push_back(y);
		p[y].push_back(x);
	}
	int Min=1;
	for(int i=1;i<=N;i++){
		if(p[i].size()<p[Min].size()){
			Min=i;
		}
	}
	vis[Min]=1;
	judge(Min);
	int l=1,r=0;
	for(int i=1;i<=N;i++){
		if(!vis[i]){
			que[++r]=i;
		}
	}
	for(int i=1;i<=r;i++){
		judge(que[i]);
	}
	cout<<cnt-1;
}

void solve(){

}

int main(){
	prepare();
	solve();
	return 0;
}
