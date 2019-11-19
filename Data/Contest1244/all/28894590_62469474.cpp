#include<bits/stdc++.h>
inline int read(){
	int x=0,w=1;
	char ch=0;
	while (ch<'0' || ch>'9'){
		ch=getchar();
		if (ch=='-') w=-1;	
	}
	while (ch<='9' && ch>='0'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*w;
}
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,ans,cnt;
char s[N];
int main(){
	//freopen("a.in","r",stdin);
	int T=read();
	while (T--){
		n=read(),ans=cnt=0;
		scanf("%s",s+1);
		for (int i=1;i<=n;++i)
			if (s[i]=='1'){
				++cnt;
				ans=max(ans,(n-i+1)<<1);
				ans=max(ans,i<<1);
			}
		ans=max(ans,n+cnt);
		printf("%d\n",ans);
	}
	return 0;
}
