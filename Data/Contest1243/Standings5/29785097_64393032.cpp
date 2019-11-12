#include<bits/stdc++.h>
using namespace std;
int n,k;
char a[10005],b[10005];
int main(){
	scanf("%d",&k);
	while(k--){
		scanf("%d",&n);
		scanf("%s",a);
		scanf("%s",b);
		int f=-1,t=0,answer=0;
		for(int i=0;i<n;i++){
			if(a[i]!=b[i]){
				if(f==-1)f=i;
				else{
					t++;
					if(t==2)break;
					if(a[i]==a[f]&&b[i]==b[f]){
						answer=1;
					}
				}
			}
		}
		if(t==1 && answer)puts("Yes");
		else puts("No");
	}
}
