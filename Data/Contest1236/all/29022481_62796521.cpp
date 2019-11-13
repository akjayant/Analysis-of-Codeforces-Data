#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e5+5;

vector<int> ans[305];

int main()
{
	int n;
	scanf("%d",&n);
	int N=n*n;
	
	int g=1,f=1,flag=0;
	while(N){
		ans[g].push_back(N);
		N--;
		if(g==n&&f==1&&!flag){
			flag=1;
			continue;
		}
		if(g==1&&f==-1&&!flag){
			flag=1;
			continue;
		}
		if(g==n&&f==1&&flag)f=-f,flag=0;
		if(g==1&&f==-1&&flag)f=-f,flag=0;
		g+=f;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<n-1;j++)
			printf("%d ",ans[i][j]);	
		printf("%d\n",ans[i][n-1]);
	}


    return 0;
}
