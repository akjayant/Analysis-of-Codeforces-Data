//Coded by dst
#include<iostream>
#include<cstdio>
using namespace std;
const long long mod=1e9+7;
string s;
int n,cnt;
long long ans=1,f[100005];
int main(){
	int i;
	cin>>s;
	n=s.length();
	f[0]=1;
	f[1]=1;
	for(i=2;i<=n;i++)
		f[i]=(f[i-1]+f[i-2])%mod;
	s+='0';
	for(i=0;i<n;i++){
		if(s[i]=='m'||s[i]=='w'){
			cout<<0;
			return 0;
		}
		cnt++;
		if(s[i]!=s[i+1]){
			if(s[i]=='u'||s[i]=='n')
				ans=ans*f[cnt]%mod;
			cnt=0;
		}
	}
	cout<<ans;
	return 0;
}