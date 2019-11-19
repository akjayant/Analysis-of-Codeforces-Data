#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
typedef pair<int,int> pii;
int n,m;
char s[N];
int vis[N][2];
queue<pair<int,int> > q;
int main(){
	int t=read();
	while(t--){
		n=read();
		scanf("%s",s+1);
		int ans=n;
		for(int i=1;i<=n;i++) if(s[i]=='1') {
			ans=max(ans,max(i,n-i+1)*2);
		}
		printf("%d\n",ans);
	}
	return 0;
} 