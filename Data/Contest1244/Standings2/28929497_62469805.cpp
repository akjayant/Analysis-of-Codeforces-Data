#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

#define maxn 1005

using namespace std;
int t,n,ans;
char s[1001];
int main(){
	scanf("%d",&t);
	for (int j=1; j<=t; j++){
		scanf("%d",&n); scanf("%s",s+1);
		ans=n;
		for(int i=1; i<=n; i++)
			if(s[i]=='1') ans=max(ans,max(i,n-i+1)<<1);
		printf("%d\n",ans);
	}
	return 0;
}