#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int maxn=1e5+5;
int f[maxn];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.size();++i)
		if(s[i]=='m'||s[i]=='w') cout<<"0"<<'\n',exit(0);
	f[1]=1;
	f[2]=2;
	for(int i=3;i<=maxn-5;++i)
		f[i]=(f[i-1]+f[i-2])%mod;
	int ans=1;
	for(int i=0;i<s.size();++i){
		if(s[i]=='u'||s[i]=='n'){
			int tmp=i;
			while(s[tmp]==s[i]) ++tmp;
			--tmp;
			ans=1ll*ans*f[(tmp-i+1)]%mod;
			i=tmp;
		}
	}
	cout<<ans<<'\n';
	return 0;
}

