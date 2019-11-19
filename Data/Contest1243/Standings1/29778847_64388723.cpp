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
	
	int n, N;
	int con = 0;
	int a = 0;
	
	cin>>n;
	
	N = n;
	
	for(int i = 2; i*i <= N; i++){
		
		if(N%i == 0) con++;
		
		while(N%i == 0){
			N /= i;
			a = i;
		}
	}
	
	if(N != 1){
		con++;
		a = N;
	}
	
	if(n == 1) a = 1;
	
	if(con >= 2) cout<<1<<endl;
	else {
		cout<<a<<endl;
	}
	
	return 0;
}