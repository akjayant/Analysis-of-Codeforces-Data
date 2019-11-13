#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;
const int N = 1e5+7;
typedef long long ll;
const ll mod = 1e9+7;
using namespace std;
ll dp[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s;
	cin>>s;
	int len=s.size();
	bool f=1;
	for(int i=0;i<len;i++){
		if(s[i]=='w'||s[i]=='m'){
			f=0;
			break;
		}
	}
	if(f){
		dp[0]=1;
		dp[1]=1;
		for(int i=2;i<=len;i++){
			dp[i]=dp[i-1];
			if(s[i-1]=='n'&&s[i-2]=='n'){
				dp[i]=(dp[i-2]+dp[i])%mod;
			}else if(s[i-1]=='u'&&s[i-2]=='u'){
				dp[i]=(dp[i-2]+dp[i])%mod;
			}
		}
		cout<<dp[len]<<"\n";
	}else{
		cout<<"0\n";
	}
	return 0;
} 