#include <bits/stdc++.h>
using namespace std;
int q,n;
char s[55],t[55];
int a[30],x[105],y[105],cnt;
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d%s%s",&n,s+1,t+1);
		memset(a,0,sizeof(a));
		bool f=true;
		//return 0;
		for(int i=1;i<=n;i++) a[s[i]-96]++,a[t[i]-96]++;
		for(int i=1;i<=26;i++)
			if(a[i]&1) {f=false;break;}
		if(!f) {printf("No\n");continue;}
		//return 0;
		cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i]==t[i]) continue;
			for(int j=i+1;j<=n;j++){
				if(s[i]==s[j]){
					swap(s[j],t[i]);
					x[++cnt]=j,y[cnt]=i;
					break;
				}
				if(s[i]==t[j]){
					swap(s[j],t[j]);
					x[++cnt]=j,y[cnt]=j;
					swap(s[j],t[i]);
					x[++cnt]=j,y[cnt]=i;
					break;
				}
			}
		}
		printf("Yes\n%d\n",cnt);
		for(int i=1;i<=cnt;i++) printf("%d %d\n",x[i],y[i]);
	}
	return 0;
}