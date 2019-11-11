#include<iostream>
#include<algorithm>
using namespace std;
const long long mx=1e9;
const long long mod=1e9+7;
const long long maxn=2e5+10;
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
long long ans=1,dp[maxn];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	dp[0]=dp[1]=1;
	for(int i=2;i<maxn;i++){
		dp[i]=dp[i-1]+dp[i-2];
		dp[i]%=mod;
	}
	string s;
	cin>>s;
	s+='#';
	int cnt=0;
	char now='u';
	for(int i=0;i<s.length();i++){
		if(s[i]=='w'||s[i]=='m'){
			cout<<0<<endl;
			return 0;
		}
		if(now==s[i]){
			cnt++;
		}else{
			if(now=='u'||now=='n'){
				ans*=dp[cnt];
				ans%=mod;
			}
			now=s[i];
			cnt=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}