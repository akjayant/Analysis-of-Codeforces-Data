#include <bits/stdc++.h>
using namespace std;
#define asp ""
#define aps ''
#define one 1
#define two 2
#define dif !=
typedef long long ll;
vector<int> g;
vector<int> f;


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		int n,m;
		cin >> n;
		int par =0;
		int imp = 0;
		for(int i=0;i<n;i++){
			int a;
			cin >> a;
			if(a%two == 0) par++;
			else imp++;
			//g.push_back(a);
		}
		cin >> m;
		ll sum = 0;
		for(int i=0;i<m;i++){
			int a;
			cin >> a;
			if(a%two == 0) sum += par;
			else sum += imp;
		}
		cout << sum << endl;
		}	
}