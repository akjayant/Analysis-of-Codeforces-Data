#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );
	
	int tc;
	cin >> tc;
	while(tc--){
		int a , b;
		cin >> a >> b;
		int g=  __gcd(a , b);
		if(g == 1){
			cout << "Finite" << endl;
		}else{
			cout << "Infinite" << endl;
		}
	}
	return 0;
}

