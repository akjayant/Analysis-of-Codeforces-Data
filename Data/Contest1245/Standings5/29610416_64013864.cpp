#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define MAXN 100005
char a[MAXN];
const ll mod=1e9+7;
ll f[MAXN];
int main(){
	cin>>a;
	ll n=strlen(a);
	f[1]=1;f[2]=2;
	for(int i=3;i<MAXN;i++)	f[i]=(f[i-1]+f[i-2])%mod;
	ll ans=1;
	for(int i=0;i<n;i++)
		if(a[i]=='m'||a[i]=='w')	return 0*printf("0\n");
	for(int i=0;i<n;i++){
		if(a[i]=='n'){
			ll l=1;
			while(a[i+1]=='n'&&i+1<n)	l++,i++;
			(ans*=f[l])%=mod;
		}
		else if(a[i]=='u'){
			ll l=1;
			while(a[i+1]=='u'&&i+1<n)	l++,i++;
			(ans*=f[l])%=mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}
