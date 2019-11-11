#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
#define pb push_back
#define fi first
#define se second
const int mod = 1e9+7;
int fib[100005];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s; 
	cin>>s;
	int n = s.size();
	fib[1] = 1;
	fib[2] = 2;
	fib[0] = 1;
	for(int i=3;i<100005;i++){
		fib[i] = (fib[i-1]+fib[i-2])%mod;
	}
	ll ans = 1;
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(s[i]=='n'){
			cnt++;
		}
		else{
			if(cnt){
				ans*=fib[cnt];
				ans%=mod;
			}
			cnt = 0;
		}
	}
	if(cnt){
		ans*=fib[cnt];
		ans%=mod;
		cnt = 0;
	}
	for(int i=0;i<n;i++){
		if(s[i]=='u'){
			cnt++;
		}
		else{
			if(cnt){

				ans*=fib[cnt];
				ans%=mod;
			}
			cnt = 0;
		}
	}
	if(cnt){
		ans*=fib[cnt];
		ans%=mod;
	}
	for(int i=0;i<n;i++){
		if(s[i]=='m' or s[i]=='w')ans = 0;
	}
	cout<<ans<<endl;
	return 0;
}
