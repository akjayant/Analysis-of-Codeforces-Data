#include<bits/stdc++.h>
using namespace std;

char s[100005];
int n,a,b,c;
char ans[100005];
bool ok[105];
int main() {
	int t;scanf("%d",&t);
	while(t--) {
		memset(ok,false,sizeof(ok));
		scanf("%d %d %d %d",&n,&a,&b,&c);
		scanf("%s",s+1);
		int cnt=0;
		ans[n+1]='\0';
		for(int i=1;i<=n;i++) {
			if(s[i]=='P'&&c) {
				c--;
				ans[i]='S';
				ok[i]=true;
				cnt++;
			}
			if(s[i]=='S'&&a) {
				a--;
				ok[i]=true;
				ans[i]='R';
				cnt++;
			}
			if(s[i]=='R'&&b) {
				b--;
				ok[i]=true;
				ans[i]='P';
				cnt++;
			}
		}
		int tot=(n+1)/2;
		if(cnt<tot) printf("NO\n");
		else {
			for(int i=1;i<=n;i++) {
				if(!ok[i]) {
					if(a) {a--;ans[i]='R';}
					else if(b) {b--;ans[i]='P';}
					else {c--;ans[i]='S';}
				}
			}
			printf("YES\n");
			printf("%s\n",ans+1);
		}
	}
}