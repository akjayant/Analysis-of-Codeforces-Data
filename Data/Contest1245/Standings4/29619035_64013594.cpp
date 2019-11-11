#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
ll ans;
int n,flag,cnt;
ll f[100005];
char a[100005],now='A';
int main(){
	ans=f[0]=f[1]=1;
	for(int i=2;i<=100000;++i)
		f[i]=(f[i-1]+f[i-2])%mod;
	scanf("%s",a);
	n=strlen(a);
	for(int i=0;i<n;++i)
		if(a[i]=='w'||a[i]=='m')
			{flag=1;break;}
	if(flag)puts("0");
	else{
		for(int i=0;i<n;++i){
			if(a[i]!=now){
				ans=(ans*f[cnt])%mod;
				cnt=0;
			}
			if(a[i]=='n'||a[i]=='u'){
				now=a[i];
				cnt++;
			}
		}
		ans=(ans*f[cnt])%mod;
		cout<<ans<<endl;
	}
	return 0;
}
