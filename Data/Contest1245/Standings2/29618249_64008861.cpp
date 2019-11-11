#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define M 1000005
#define mod 1000000007ll
using namespace std;
char s[M];
long long ans=1,F[M];
int n;
bool flag;
int read(){
    char c=getchar();int ans=0;
    while (c<'0'||c>'9') c=getchar();
    while (c>='0'&&c<='9') ans=(ans<<1)+(ans<<3)+(c^48),c=getchar();
    return ans;
}
long long add(long long u,long long v){return (u+=v)>=mod?u-mod:u;}
int main(){
	scanf("%s",s+1);n=strlen(s+1);F[1]=F[0]=1;
	for (register int i=2;i<=n;i++) F[i]=add(F[i-1],F[i-2]);
	for (register int i=1;i<=n;i++){
		if (s[i]=='w'||s[i]=='m'){printf("0");return 0;}
		if (s[i]!='u'&&s[i]!='n') continue;
		int j=i+1;flag|=(i<n&&s[i]==s[i+1]);
		while (j<=n&&s[j]==s[i]) j++;j--;
		ans=ans*F[j-i+1]%mod;i=j;
	}
	printf("%lld",ans);
	return 0;
}
