#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

#define int long long
#define endl "\n"

const long long INF = (long long)1e18;
const long long MOD = 1'000'000'007; 

string yn(bool f){return f?"Finite":"Infinite";}
string YN(bool f){return f?"YES":"NO";}



signed main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	
	int t;
	
	cin>>t;
	
	while(t--){
		int a, b;
		
		cin>>a>>b;
		
		cout<<yn(__gcd(a,b) == 1)<<endl;
	}
	
	
	return 0;
}