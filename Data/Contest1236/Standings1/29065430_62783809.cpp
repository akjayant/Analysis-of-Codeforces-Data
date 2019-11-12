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
		int a, b, c;
		cin >>  a >> b >> c;
		int x = min(b, c/2);
		int ans=0;
		ans+=3*x;
		b-=x;
		ans+=3*min(a, b/2);
		cout << ans << endl;
	}
}