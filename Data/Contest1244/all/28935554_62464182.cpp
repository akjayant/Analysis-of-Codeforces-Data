#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int q; cin >> q;
	for(int z=0;z<q;z++){
		int a,b,c,d,e; cin >> a >> b >> c >> d >> e;
		if((a+c-1)/c+(b+d-1)/d>e){
			cout << -1 << endl;
		}
		else{
			cout << (a+c-1)/c << " " << (b+d-1)/d << endl;
		}
	}
}