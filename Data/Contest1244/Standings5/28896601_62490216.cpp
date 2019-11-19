#include <bits/stdc++.h>
#define LL long long
const int N=1e5+10;
const LL inf=1e15+10;
int n;
std::vector<int> p[N];
int bo[N];
int c[4][N];
int a[N];
int ta[N];
LL f[7][N];
int number[N];

int make(int x,int y){
	if(x==1&&y==2)return 1;
	else if(x==1&&y==3)return 2;
	else if(x==2&&y==1)return 3;
	else if(x==2&&y==3)return 4;
	else if(x==3&&y==1)return 5;
	else if(x==3&&y==2)return 6;
	else return 0;
}
void dfs(int x,int num){
	bo[x]=true;
	a[num]=x;
	ta[x]=num;
	for(auto it:p[x])
		if(!bo[it])
			dfs(it,++num);
}
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);std::cout.tie(0);
	std::cin>>n;
	for(int j=1;j<=3;++j)
	for(int i=1;i<=n;++i)
		std::cin>>c[j][i];
	int u,v;
	for(int i=1;i<n;++i){
		std::cin>>u>>v;
		p[u].push_back(v);
		p[v].push_back(u);
	}
	for(int i=1;i<=n;++i)
		if(p[i].size()>2){
			std::cout<<"-1\n";
			return 0;
		}
	for(int i=1;i<=n;++i)
		if(p[i].size()==1){
			dfs(i,1);
			break;
		}
	for(int j=0;j<7;++j)
	for(int i=1;i<=n;++i)
		f[j][i]=inf;
	for(int i=1;i<=3;++i)
		for(int j=1;j<=3;++j)
			if(i!=j)
				f[make(i,j)][2]=c[i][a[1]]+c[j][a[2]];
	for(int k=3;k<=n;++k)
		for(int i=1;i<=3;++i)
			for(int j=1;j<=3;++j)
				if(i!=j)
					f[make(i,j)][k]=f[make(6-i-j,i)][k-1]+c[j][a[k]];
	int ii,jj;
	LL ans=inf;
	for(int i=1;i<=3;++i)
		for(int j=1;j<=3;++j)
			if(i!=j)
				if(ans>f[make(i,j)][n]){
					ans=f[make(i,j)][n];
					ii=i,jj=j;
				}
	number[n]=jj;
	number[n-1]=ii;
	for(int i=n-2;i;--i)
		number[i]=6-number[i+1]-number[i+2];
	std::cout<<ans<<'\n';
	for(int i=1;i<=n;++i)
		std::cout<<number[ta[i]]<<' ';	
	return 0;
}

