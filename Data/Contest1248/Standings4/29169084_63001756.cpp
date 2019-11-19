#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+10,mod=1e9+7;
void read(int &x){
	char c=getchar();
	int f=1;
	x=0;
	while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
int f[maxn][4];
signed main(){
	int i,j,k,m,n;
	read(n);read(m); 	
	int num=max(n,m);

	f[2][1]=f[2][2]=f[2][3]=f[2][0]=1;
	for(register int i=3;i<=num;i++){
		f[i][0]=f[i-1][1]%mod;
		f[i][3]=f[i-1][2]%mod;
		f[i][1]=(f[i-1][3]+f[i-1][2])%mod;
		f[i][2]=(f[i-1][0]+f[i-1][1])%mod;
	}
	int ansn=(f[n][1]+f[n][0]+f[n][2]+f[n][3])%mod,ansm=(f[m][1]+f[m][0]+f[m][2]+f[m][3])%mod;
	if(n==1)ansn=2;if(m==1)ansm=2;
	int ans=((ansn+ansm)%mod-2+mod)%mod;
	cout<<ans<<endl;
	return 0;	
}
