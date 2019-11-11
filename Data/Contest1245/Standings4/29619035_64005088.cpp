#include<bits/stdc++.h>
using namespace std;
int a[3],n,cnt,flag,T;
char q[3]={'R','P','S'},o[3]={'S','R','P'};
char p[105],b[105];
bool vis[105];
int main(){
	scanf("%d",&T);
	for(int t=1;t<=T;++t){
		memset(vis,0,sizeof(vis));cnt=0;
		scanf("%d",&n);
		scanf("%d%d%d",&a[0],&a[1],&a[2]);
		scanf("%s",p);
		for(int i=0;i<n;++i)
			for(int j=0;j<3;++j)
				if(p[i]==o[j]){
					p[i]=q[j];
					break;
				}
		for(int i=0;i<n;++i){
			for(int j=0;j<3;++j){
				if(p[i]==q[j]){
					if(a[j]){
						a[j]--;
						cnt++;
						b[i]=q[j];
						vis[i]=1;
					}
				}
			}
		} 
		flag=(n+1)/2;
		if(cnt>=flag){
			puts("YES");
			for(int i=0;i<n;++i){
				if(vis[i])printf("%c",b[i]);
				else {
					for(int j=0;j<3;++j){
						if(a[j]){
							printf("%c",q[j]);
							a[j]--;
							break;
						}
					}
				}
			}
			puts("");
		}
		else puts("NO");
	}
	return 0;
}
