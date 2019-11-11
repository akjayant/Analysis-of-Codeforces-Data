#include <cstdio>
#include <cstdlib>
#include <cstring>
#define N 1000001
#define MOD 1000000007
#define rnt register int
using namespace std;
char s[N];
int len,ans[N];
signed main(){
	scanf("%s",s);
	len=strlen(s);
	ans[0]=ans[1]=1;
	if(s[0]=='m' || s[0]=='w') return printf("0"),0;
	for(rnt i=1;i<len;i=-~i){
		if(s[i]=='m' || s[i]=='w') return printf("0"),0;
		ans[i+1]=(ans[i+1]+ans[i])%MOD;
		if(s[i]=='n' && s[i-1]=='n') ans[i+1]=(ans[i+1]+ans[i-1])%MOD;
		if(s[i]=='u' && s[i-1]=='u') ans[i+1]=(ans[i+1]+ans[i-1])%MOD;
	}
	return printf("%d",ans[len]),0;
}
