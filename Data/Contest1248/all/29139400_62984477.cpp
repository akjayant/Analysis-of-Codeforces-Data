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
	
	int n;
	vector<int> a;
	int b = 0, c = 0;
	
	cin>>n;
	
	a.resize(n);
	
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	
	sort(a.begin(), a.end(), greater<int>());
	
	for(int i = 0; i < (n+1)/2; i++){
		b += a[i];
	}
	for(int i = (n+1)/2; i < n; i++){
		c += a[i];
	}
	
	cout<<b*b+c*c<<endl;
	return 0;
}