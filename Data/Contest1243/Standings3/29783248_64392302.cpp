/*
 * @Author: Snicky
 * @Date: 2019-11-06 23:41:00 
 * @Last Modified by: Simon
 * @Last Modified time: 2019-11-06 23:41:00
 */ 
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 200005
#define INF 0x3f3f3f3f
vector<int>fac;
void solve(int n){
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			fac.push_back(i);
			if(i*i!=n) fac.push_back(n/i);
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;solve(n);
	int ans=0;
	if(fac.size()==0){
		ans=n;
	}
	else
	for(auto v:fac){
		ans=__gcd(ans,v);
	}
	cout<<ans<<endl;
	return 0;
}
