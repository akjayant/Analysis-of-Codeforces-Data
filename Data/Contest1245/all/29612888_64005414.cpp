#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;
const LL sac=1e9+7;
#define foru(i,a,b) for(LL i=a;i<=b;i++)
#define ford(i,a,b) for(LL i=a;i>=b;i--)
LL ans,n,f[100005];
char s[100005];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	f[1]=1;f[2]=2;f[3]=3;
	foru(i,4,n){
		f[i]=f[i-1]+f[i-2];
		f[i]%=sac;
	}
	LL p=1,q,ans=1;
	while(p<n){
		if(s[p]=='w'||s[p]=='m')ans=0;
		if(s[p]!='u'&&s[p]!='n'){p++;continue;}
		q=1;
		while(s[p+q]==s[p])q++;
		ans*=f[q];
		ans%=sac;
		p+=q;
	}
	printf("%I64d",ans);
	return 0;
}
