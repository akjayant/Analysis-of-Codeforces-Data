#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
typedef long long LL;
const int mod=1e9+7;
string s;
LL f[100005],ans=1;
int main(){
	ios::sync_with_stdio(false);
	cin>>s;
	if(s.find('m')!=-1||s.find('w')!=-1){
		cout<<0<<endl;
		return 0;
	}
	f[0]=1;
	f[1]=2;
	for(int i=2;i<=100000;++i)
		f[i]=(f[i-1]+f[i-2])%mod;
	for(int i=0;i<s.size();++i){
		if(s[i]!='u'&&s[i]!='n')
			continue;
		LL cnt=0;
		while(i+1<s.size()&&s[i+1]==s[i])
			++cnt,++i;
		ans=ans*f[cnt]%mod;
	}
	cout<<ans<<endl;
	return 0;
}
