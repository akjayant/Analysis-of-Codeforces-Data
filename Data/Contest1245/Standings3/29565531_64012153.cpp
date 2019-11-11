#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const ll mod=1e9+7;
ll dp[maxn],n,ans=1,last[maxn];
string s;
void init(){
	dp[1]=1;
	dp[2]=2;
	for (int i=3;i<=n;i++){
		dp[i]=(dp[i-1]+dp[i-2])%mod;
	}
}
int main(){
	cin>>s;
	n=s.size();
	s=" "+s;
	for (int i=1;i<=n;i++){
		if (s[i]=='w'||s[i]=='m'){
			cout<<"0"<<endl;
			return 0;
		}
		if (s[i]==s[i-1]){
			last[i]=last[i-1];
		}
		else last[i]=i;
	}
	init();
	for (int i=1;i<=n;i++){
		if (i==n||s[i]!=s[i+1]){
			if (s[i]=='u'||s[i]=='n'){
				ll len=i-last[i]+1;
				ans=ans*dp[len]%mod;
			}
		}
	}
	cout<<ans<<endl;
}