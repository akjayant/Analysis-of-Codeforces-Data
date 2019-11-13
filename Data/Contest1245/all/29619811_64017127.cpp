#include <bits/stdc++.h>
#define pi acos(-1.0)
#define ll long long
#define lf double
#define ull unsigned long long
#define esp 1e-9
#define inf 0x3f3f3f3f
#define inff 0x3f3f3f3f3f3f3f3f
#define Pair pair<ll, ll>
#define It map<ll, ll>::iterator
#define CLR(x, a) memset(x, a, sizeof(x))
    
using namespace std;

const ll N = 1e5+5, mod=1e9+7;
ll dp[N]; 
string str;

int main(){
	ios::sync_with_stdio(false);
	cin>>str;
    ll f = 1, len = str.length();
    dp[0] = 1;
    for(ll i = 1; i <= len; i++){
    	dp[i] = dp[i-1];
    	if(str[i-1]=='w' || str[i-1]=='m') {
    		f = 0; cout<<0<<endl;
    		break;
		}
    	if(str[i-1]=='u' || str[i-1]=='n'){
    		if(str[i-1] == str[i-2]){
    			dp[i] = (dp[i-2]%mod+dp[i]%mod)%mod;
			} 
		}
	}
	if (f){
		cout<<dp[len]<<endl;
	}
	
    return 0;
}