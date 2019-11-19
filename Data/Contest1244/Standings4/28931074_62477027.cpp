#include<bits/stdc++.h>
using namespace std;

int T,n;

char str[1005];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s",str+1);
		int last=0,js=0,totol=0,ans=0;
		for(int i=1;i<=n;i++){
			if(str[i]=='1'){
				totol=max(2*i,totol);
				js++;last=i;
			}
		}
		ans=js+n;last=n+1;js=0;
		ans=max(ans,totol);
		for(int i=n;i>=1;i--){
			if(str[i]=='1'){
				totol=max(2*(n-i+1),totol);
				js++;last=i;
			}
		}
		ans=max(ans,totol);
		printf("%d\n",ans);
	}
	return 0;
}