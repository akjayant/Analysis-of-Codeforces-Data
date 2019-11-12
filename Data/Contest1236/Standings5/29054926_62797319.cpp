#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;



int main(){
	fast;
	int n;
	cin >> n;
	vector<int> v[n + 1];
	int ct = 1, xr = 0;
	for(int i = 1; i <= n * n; i++){
		if(xr == 0){
			v[ct++].push_back(i);
		}
		else{
			v[ct--].push_back(i);
		}
		if(ct == n + 1){
			xr ^= 1;
			ct = n;
		}
		if(ct == 0){
			xr ^= 1;
			ct = 1;
		}
	}
	for(int i = 1; i <= n; i++){
		for(auto j : v[i]) cout << j << " ";
		cout << "\n";
	}
}