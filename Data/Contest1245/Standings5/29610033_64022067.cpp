#include<bits/stdc++.h>
using namespace std;
int t,n,a[105],b[5],c[5],ans[105];
char ch[5],str[105];
int main(){
	int i,j;
	scanf("%d",&t);
	ch[1]='R'; ch[2]='P'; ch[3]='S';
	while (t--){
		scanf("%d%d%d%d",&n,&c[1],&c[2],&c[3]);
		scanf("%s",str+1);
		memset(b,0,sizeof(b));
		for (i=1;i<=n;i++)
		for (j=1;j<=3;j++)
		if (str[i]==ch[j]) a[i]=j,b[j]++;
		if (min(b[1],c[2])+min(b[2],c[3])+min(b[3],c[1])<(n+1)/2) printf("NO\n");
		else{
			printf("YES\n");
			memset(ans,0,sizeof(ans));
			for (i=1;i<=n;i++)
			if (c[a[i]%3+1]) ans[i]=a[i]%3+1,c[a[i]%3+1]--;
			for (i=1;i<=n;i++)
			if (!ans[i]) for (j=1;j<=3;j++)
			if (c[j]){
				ans[i]=j; c[j]--;
				break;
			}
			for (i=1;i<=n;i++) printf("%c",ch[ans[i]]);
			printf("\n");
		}
	}
	return 0;
}