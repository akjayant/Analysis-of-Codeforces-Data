#include<bits/stdc++.h>
#define M 100005
using namespace std;
int n,in[M],s1[M],s2[M],s3[M],num[M],done[M],link[M];
int cnt;
vector<int>E[M];
void dfs(int x,int f) {
	link[++cnt]=x;
	for(int i=0; i<E[x].size(); i++) {
		int v=E[x][i];
		if(v==f)continue;
		dfs(v,x);
	}
	return ;
}
void check() {
	bool f=false;
	for(int i=1; i<=n; i++) {
		if(done[i]<num[i]) {
			f=true;
			break;
		} else if(done[i]>num[i])break;
	}
	if(f)for(int i=1; i<=n; i++)num[i]=done[i];
	return;
}
int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++)scanf("%d",&s1[i]);
	for(int i=1; i<=n; i++)scanf("%d",&s2[i]);
	for(int i=1; i<=n; i++)scanf("%d",&s3[i]);
	for(int i=1; i<n; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		in[a]++;
		in[b]++;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	num[1]=4;
	int rt=0;
	for(int i=1; i<=n; i++) {
		if(in[i]>=3) {
			puts("-1");
			return 0;
		}
		if(in[i]==1)rt=i;
	}
	dfs(rt,0);
	long long mn=1e18;
	long long now=0;
	for(int i=1; i<=n; i++) {
		if(i%3==0)now+=s1[link[i]],done[link[i]]=1;
		else if(i%3==1)now+=s2[link[i]],done[link[i]]=2;
		else if(i%3==2)now+=s3[link[i]],done[link[i]]=3;
	}
	if(now<mn) {
		mn=now;
		num[1]=4;
		check();
	} else if(now==mn)check();
	now=0;
	for(int i=1; i<=n; i++) {
		if(i%3==0)now+=s1[link[i]],done[link[i]]=1;
		else if(i%3==1)now+=s3[link[i]],done[link[i]]=3;
		else if(i%3==2)now+=s2[link[i]],done[link[i]]=2;
	}
	if(now<mn) {
		mn=now;
		num[1]=4;
		check();
	} else if(now==mn)check();
	now=0;
	for(int i=1; i<=n; i++) {
		if(i%3==0)now+=s2[link[i]],done[link[i]]=2;
		else if(i%3==1)now+=s1[link[i]],done[link[i]]=1;
		else if(i%3==2)now+=s3[link[i]],done[link[i]]=3;
	}
	if(now<mn) {
		mn=now;
		num[1]=4;
		check();
	} else if(now==mn)check();
	now=0;
	for(int i=1; i<=n; i++) {
		if(i%3==0)now+=s2[link[i]],done[link[i]]=2;
		else if(i%3==1)now+=s3[link[i]],done[link[i]]=3;
		else if(i%3==2)now+=s1[link[i]],done[link[i]]=1;
	}
	if(now<mn) {
		mn=now;
		num[1]=4;
		check();
	} else if(now==mn)check();
	now=0;
	for(int i=1; i<=n; i++) {
		if(i%3==0)now+=s3[link[i]],done[link[i]]=3;
		else if(i%3==1)now+=s1[link[i]],done[link[i]]=1;
		else if(i%3==2)now+=s2[link[i]],done[link[i]]=2;
	}
	if(now<mn) {
		mn=now;
		num[1]=4;
		check();
	} else if(now==mn)check();
	now=0;
	for(int i=1; i<=n; i++) {
		if(i%3==0)now+=s3[link[i]],done[link[i]]=3;
		else if(i%3==1)now+=s2[link[i]],done[link[i]]=2;
		else if(i%3==2)now+=s1[link[i]],done[link[i]]=1;
	}
	if(now<mn) {
		mn=now;
		num[1]=4;
		check();
	} else if(now==mn)check();
	printf("%lld\n",mn);
	for(int i=1; i<=n; i++)printf("%d ",num[i]);
	return 0;
}