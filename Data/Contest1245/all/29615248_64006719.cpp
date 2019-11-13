#include<bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9+7;
 
long long fib[100005];
 
int main(){
	
	fib[0] = 1;
	fib[1] = 1;
	for(int i=2;i<=1e5+1;i++){
		fib[i] = fib[i-1] + fib[i-2];
		fib[i] %= MOD;
	}
	bool hano = false;
	string s;
	cin>>s;
	vector<int> v;
	long long ans = 1;
	int n = s.size();
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(s[i] == 'm' || s[i] == 'w') hano=true;
		if(s[i] == 'u'){
			cnt++;
		}
		else{
			v.push_back(cnt);
			cnt = 0;
		}
	}
	v.push_back(cnt);
	cnt = 0;
	for(int i=0;i<n;i++){
		if(s[i] == 'n'){
			cnt++;
		}
		else{
			v.push_back(cnt);
			cnt = 0;
		}
	}
	v.push_back(cnt);
	for(int x:v){
		ans *= fib[x];
		ans %= MOD;
	}
	if(hano){
		cout<<0;
		return 0;
	}
	cout<<ans;
	
	return 0;
}
