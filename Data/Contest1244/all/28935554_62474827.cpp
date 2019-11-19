#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	ll n,p,x,y; cin >> n >> p >> x >> y;
	if(p%x==0&&p/x<=n){
		cout << p/x << " " << 0 << " " << n-p/x << endl;
		return 0;
	}
	ll ma=p/x;
	if(ma>=n){
		cout << -1 << endl;
		return 0;
	}
	for(ll i=ma;i>=max(0LL,ma-y-1);i--){
		if((p-i*x)%y==0&&i+(p-i*x)/y<=n){
			cout << i << " " << (p-i*x)/y << " " << n-i-(p-i*x)/y << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}