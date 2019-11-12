#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int maxn=305;
vector<int>G[maxn];
int main(){
	int n=read();
	int cnt=1,f=1;
	for(int i=1;i<=n*n;i++){
		G[cnt].push_back(i);
		cnt+=f;
		if(cnt==n+1)f*=-1,cnt=n;
		if(cnt==0)f*=-1,cnt=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<(int)G[i].size();j++)cout<<G[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}
