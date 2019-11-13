#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MOD	1000000007
#define int	long long
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		if(a == b){
			cout << "Yes\n";
		}
		else{
			vector<pair<char,char>> v;
			for(int i = 0; i < n; i++){
				if(a[i] != b[i]){
					v.PB({a[i],b[i]});
				}
			}
			if(v.size() != 2){
				cout << "No\n";
			}
			else{
				if(v[0].F == v[1].F && v[0].S == v[1].S){
					cout << "Yes\n";
				}
				else
					cout << "No\n";
			}
		}
	}

	return 0;
}

