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

string yn(bool f){return f?"Yes":"No";}
string YN(bool f){return f?"YES":"NO";}



signed main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	
	int t;
	
	cin>>t;
	
	for(int i = 0; i < t; i++){
		int n, m;
		int con0 = 0, con1 = 0;
		int con02 = 0, con12 = 0;
		cin>>n;
		
		for(int i = 0; i < n; i++){
			int p;
			cin>>p;
			if(p%2) con1++;
			else con0++;
		}
		
		cin>>m;
		
		for(int i = 0; i < m; i++){
			int p;
			cin>>p;
			if(p%2) con12++;
			else con02++;
		}
		
		cout<<con0*con02+con1*con12<<endl;
	}
	
	
	
	return 0;
}