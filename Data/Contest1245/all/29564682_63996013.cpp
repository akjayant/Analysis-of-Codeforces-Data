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

#define N 1000007 //10e6 +7

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int a, b;
		cin >> a >> b;
		if(__gcd(a, b)==1)cout << "Finite" << endl;
		else cout << "Infinite" << endl;
	}
}