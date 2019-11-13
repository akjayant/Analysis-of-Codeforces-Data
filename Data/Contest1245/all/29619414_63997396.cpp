#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;
const int N = 1e5+7;
typedef long long ll;
const ll mod = 1e9+7;
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		int c=__gcd(a,b);
		if(c==1){
			cout<<"Finite\n";
		}else{
			cout<<"Infinite\n";
		}
	} 
	return 0;
} 