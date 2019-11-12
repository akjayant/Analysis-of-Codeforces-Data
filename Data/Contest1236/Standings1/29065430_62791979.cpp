#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second
#define se second
#define fi first
#define pb push_back
#define eb emplace_back
#define mk make_pair

#define N 1007 //10e6 +7

vector<int>v[N];

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int cc=1;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			v[j].pb(cc++);
		}
		i++;
		if(i>=n)break;

		for(int j=n-1; j>=0; j--){
			v[j].pb(cc++);
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << v[i][j] << " \n"[j==n-1];
		}
	}
}