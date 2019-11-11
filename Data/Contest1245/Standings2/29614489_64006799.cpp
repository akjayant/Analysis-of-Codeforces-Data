#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int T,n,a,b,c,sum; bool vis[105];
char q[105],w[105];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&n,&a,&b,&c);
		memset(vis,0,sizeof(vis));
		scanf("%s",q+1); sum=0;
		for(int i=1;i<=n;++i){
			if(q[i]=='R'){
				if(b) --b,w[i]='P',++sum,vis[i]=1;
			}
			if(q[i]=='P'){
				if(c) --c,w[i]='S',++sum,vis[i]=1;
			}
			if(q[i]=='S'){
				if(a) --a,w[i]='R',++sum,vis[i]=1;
			}
		}
		for(int i=1;i<=n;++i) if(!vis[i]){
			if(a) --a,w[i]='R';
			else if(b) --b,w[i]='P';
			else if(c) --c,w[i]='S';
		}
		if(sum>=(n+1)/2){
			puts("YES");
			for(int i=1;i<=n;++i) cout<<w[i];
			cout<<endl;
		}else puts("NO");
	}return 0;
}
