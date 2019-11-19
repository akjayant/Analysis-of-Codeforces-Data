#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
#define x first
#define y second
#define mp make_pair

ll n;
vector <ll> v;

int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
cin >> n;
ll poc = n;
for(ll i = 2 ; i * i <= n ; ++i){
	if(n % i == 0){
		while(n % i == 0){
			n /= i;
		}
		v.push_back(i);
	}
}
if(n == poc){
	cout << n << endl;
	return 0;
}
if(n > 1){
	v.push_back(n);
}
if((int)v.size() == 1){
	cout << v[0] << endl;
	return 0;
}
cout << 1 << endl;

return 0;
}

