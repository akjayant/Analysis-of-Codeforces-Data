#include <bits/stdc++.h>
 
using namespace std;
typedef long long LL;
typedef pair<int,int>pa;
priority_queue<pa,vector<pa>, greater<pa> >q;

int n;
const int N=100010;
const LL mod=1000000007;
char ch[N];
LL f[N];
int main(){
#ifdef WK
	freopen("in.txt","r",stdin);
#endif
	scanf("%s",ch+1);
	n=strlen(ch+1);
	f[0]=1,f[1]=1;
	for(int i=2;i<=n;i++)f[i]=(f[i-1]+f[i-2])%mod;
	
	LL ans=1;
	for(int i=1,j=1;i<=n;){
		while(j<=n&&ch[j]==ch[i]){
			j++;
		}
		if(ch[i]=='m'||ch[i]=='w'){
			printf("0\n");
			return 0;
		}
		if(ch[i]!='n'&&ch[i]!='u'){
			i=j;continue;
		}
		ans=(ans*f[j-i])%mod;
		i=j;
	} 
	printf("%lld\n",ans);
	return 0; 
} 