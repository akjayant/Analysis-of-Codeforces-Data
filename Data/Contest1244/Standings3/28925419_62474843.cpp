#include<bits/stdc++.h>
#define N 1005
using namespace std;
bool cur1;
int n;
int sum[N];
char str[N];
bool a[N];
inline void Rd(int &res){
	char c;res=0;
	while(c=getchar(),c<48);
	do res=(res<<3)+(res<<1)+(c^48);
	while(c=getchar(),c>47);
	return;
}
bool cur2;
int main(){
//	printf("%lf MB\n",(&cur2-&cur1)/1024.0/1024);
	int T;
	Rd(T);
	while(T--){
		Rd(n);
		scanf("%s",str+1);
		for(int i=1;i<=n;i++)a[i]=str[i]-'0';
		for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
		if(!sum[n]){
			printf("%d\n",n);continue;
		}
		int l=1,r=n,ans=n+sum[r]-sum[l-1];
		while(!a[l])l++;
		while(!a[r])r--;
		ans=max(ans,max(l*2,(n-l+1)*2));
		ans=max(ans,max(r*2,(n-r+1)*2));
		printf("%d\n",ans);
	}
	return 0;
}