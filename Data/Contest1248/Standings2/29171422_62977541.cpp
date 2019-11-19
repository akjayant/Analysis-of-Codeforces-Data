#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define pb push_back 
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		ll a = 0, b = 0, c = 0, d = 0;
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			if(x % 2)
				b++;
			else a++;
		}
		int m;
		cin >> m;
		for(int i = 0; i < m; i++){
			int x;
			cin >> x;
			if(x % 2)
				d++;
			else c++;
		}
		cout << a * c + b * d << '\n';
	}

}