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
const int N=100005;
int n;
char s[N],t[N];
int b[N];
int main(){
	int T=read();
	while(T--){
		scanf("%d",&n);
		scanf("%s",s+1);
		scanf("%s",t+1);
		int num=0;
		for(int i=1;i<=n;i++) if(s[i]!=t[i]) b[++num]=i;
		if(num>2||num==1) {
			puts("No");
		}else {
			if(s[b[1]]==s[b[2]]&&t[b[1]]==t[b[2]]) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}