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
	
	int T;
	
	cin>>T;
	
	for(int i = 0; i < T; i++){
		int n, maximum = 0;
		vector<int> a;
		
		cin>>n;
		
		a.resize(n);
		
		for(int j = 0; j < n; j++){
			cin>>a[j];
		}
		
		sort(a.begin(), a.end(), greater<int>());
		
		for(int j = 0, minimum = INF; j < n; j++){
			minimum = min(minimum, a[j]);
			maximum = max(maximum, min(minimum, j+1));
		}
		
		cout<<maximum<<endl;
	}
	
	
	
	return 0;
}