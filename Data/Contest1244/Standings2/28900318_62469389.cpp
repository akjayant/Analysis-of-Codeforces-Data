#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
char s[100000];
int main(){
    scanf("%d",&t);
    while(t--){
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	    if(s[i]=='1')
		ans=max(ans,max(n-i+1,i));
	printf("%d\n",max(ans*2,n));
	ans=0;
    }
}
