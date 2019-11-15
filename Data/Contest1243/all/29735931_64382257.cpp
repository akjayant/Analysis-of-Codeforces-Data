#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first 
#define Y second
const int inf=0x3f3f3f3f;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
const int N=55;
int n;
char s[N],t[N];
int num[30],b[N];
pair<int,int> ans[N*2];
int main(){
	int T=read();
	while(T--){
		memset(num,0,sizeof(num));
		scanf("%d",&n);
		scanf("%s",s+1);
		scanf("%s",t+1);
		for(int i=1;i<=n;i++) num[s[i]-'a']++,num[t[i]-'a']++;
		int flag=0;
		for(int i=0;i<26;i++) if(num[i]%2==1) {
			puts("No");
			flag=1;break;
		}
		if(flag) continue;
		int cnt=0;
		
		for(int i=1;i<=n;i++) {
			if(s[i]!=t[i]){
				for(int j=i+1;j<=n;j++) 
					if(t[i]==t[j]) {
						ans[++cnt]={i,j};
						swap(s[i],t[j]);
						break;
					} else if(s[i]==s[j]) {
						ans[++cnt]={j,i};
						swap(s[j],t[i]);
						break;
					}else if(s[i]==t[j]){
						ans[++cnt]={i+1,j};
						swap(s[i+1],t[j]);
						ans[++cnt]={i+1,i};
						swap(s[i+1],t[i]);
						break;
					}else if(t[i]==s[j]){
						ans[++cnt]={j,i+1};
						ans[++cnt]={i,i+1};
						swap(s[j],t[i+1]);
						swap(s[i],t[i+1]);
						break;
					}
			}
		}
		puts("Yes");
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;i++) printf("%d %d\n",ans[i].X,ans[i].Y);
		
	}
	return 0;
}