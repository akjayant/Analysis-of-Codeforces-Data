/*input
3

*/
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define x first
#define y second
#define inf INT_MAX / 2ll
#define all(a) a.begin(), a.end()
#define db(a) cout << fixed << #a << " = " << a << endl;
#define ld long double
using namespace std;

int main(){
	int n;
	cin >> n;

	vector<int> group[n];

	int now = 1;
	for(int i = 0; i < n; i++){
		if(i % 2)
			for(int j = 0; j < n; j++) group[j].push_back(now++);
		else 
			for(int j = n-1; j > -1; j--) group[j].push_back(now++);
	}

	for(int i = 0; i < n; i++){
		for(int j : group[i]){
			cout << j << " ";
		}
		cout << endl;
	}


}
