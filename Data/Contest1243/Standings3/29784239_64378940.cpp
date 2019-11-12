#include <bits/stdc++.h>
using namespace std;
int q,n;
char s[10050],t[10050];
int a[10050];
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d%s%s",&n,s+1,t+1);
		a[0]=0;
		for(int i=1;i<=n;i++)
			if(s[i]!=t[i]) a[++a[0]]=i;
		if(a[0]!=0&&a[0]!=2) {printf("No\n");continue;}
		if(a[0]==0) {printf("Yes\n");continue;}
		if(s[a[1]]==s[a[2]]&&t[a[1]]==t[a[2]]) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}