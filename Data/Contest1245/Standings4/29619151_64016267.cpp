#include<iostream>

using namespace::std;

#define MOD 1000000007

long long int fac[100005],rev[100005];

int main(){
	//freopen("in.txt","r",stdin);
	fac[0]=1;
	for(int i=1;i<=100000;i++)
		fac[i]=(i*fac[i-1])%MOD;
	rev[1]=1;
	for(int i=2;i<=100000;i++)
		rev[i]=(MOD-(((MOD/i)%MOD)*rev[MOD%i])%MOD)%MOD;
	//cout<<fac[3]*rev[2]%MOD<<'\n';
	rev[0]=1;
	for(int i=2;i<=100000;i++)
		rev[i]=(rev[i]*rev[i-1])%MOD;
	//cout<<(fac[5]*rev[3])%MOD<<'\n';
	string s;
	cin>>s;
	long long int ans=1;
	for(int i=0;i<s.length();){
		if(s[i]=='w' || s[i]=='m'){
			ans*=0;
		}
		if(s[i]=='u' || s[i]=='n'){
			int consec=1;
			i++;
			while(i<s.length() && s[i]==s[i-1]) consec++,i++;
			long long int sum=0;
			for(int j=0;j*2<=consec;j++)
				sum=(sum+(((fac[consec-j]*rev[consec-j*2])%MOD)*rev[j])%MOD)%MOD;
			ans=(ans*sum)%MOD;
		}else i++;
	}
	cout<<ans<<'\n';
}
