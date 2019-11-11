#include<cstdio>
using namespace std;
char s[100010];
const int MOD=1000000007;
long long f[100010];
long long ans=1ll;
int main()
{
	f[1]=1ll;f[2]=2ll;
	for(int i=3;i<=100000;i++){
		f[i]=(f[i-1]+f[i-2])%MOD;
	}
	scanf("%s",s);
	for(int i=0;s[i];i++){
		if(s[i]=='w'||s[i]=='m') return 0*puts("0");
		int x=i+1,ok=0;
		if(s[i]=='u'){
			while(s[x]=='u') x++;ok=1;
		}
		if(s[i]=='n'){
			while(s[x]=='n') x++;ok=1;
		}
		int l=x-i;
		if(ok) ans=(ans*f[l])%MOD;
		i=x-1;
	}
	printf("%lld\n",ans);
}