#include<bits/stdc++.h>
#define ll long long 
using namespace std;
char s[105];
char ans[105];
int vis[105];
int a,b,c;
int n;
int main(){
	int t;cin>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		scanf("%d",&n);
		cin>>a>>b>>c;
		scanf("%s",s);
		int win=0;
		for(int i=0;i<n;i++){
			if(s[i]=='R'&&b){
				b--;ans[i]='P';
				win++;
				vis[i]=1;
			}
			if(s[i]=='P'&&c){
				c--;ans[i]='S';
				win++;
				vis[i]=1;
			}
			if(s[i]=='S'&&a){
				a--;ans[i]='R';
				win++;
				vis[i]=1;
			}
		}
		if(win<(n+1)/2){
			puts("NO");
			continue;
		}
		for(int i=0;i<n;i++){
			if(vis[i])continue;
			if(a){
				a--;ans[i]='R';
			}	
			else if(b){
				b--;ans[i]='P';
			}
			else if(c){
				c--;ans[i]='S';
			}
		}
		puts("YES");
		for(int i=0;i<n;i++)cout<<ans[i];
		puts("");
	}
	return 0;
}