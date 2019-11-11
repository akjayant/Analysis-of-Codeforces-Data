#include<cstdio>
typedef long long ll;
const int N=1e5+5;
const ll mod=1e9+7;
ll ans=1,f[N][2];
char sr[N];
int main(){
	f[1][0]=1;
	for(int i=2;i<N;++i)
		f[i][0]=(f[i-1][0]+f[i-1][1])%mod,f[i][1]=f[i-1][0]; 
	scanf("%s",sr);
	for(int i=0,j;sr[i];++i)
		if(sr[i]=='u'||sr[i]=='n'){
			for(j=i+1;;++j)
				if(sr[j]!=sr[i]) break; 
			ans=(ans*(f[j-i][0]+f[j-i][1]))%mod;
			i=j-1;
		}
		else if(sr[i]=='m'||sr[i]=='w') ans=0;
	printf("%lld",ans);
	return 0;
}