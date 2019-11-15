#include<bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using ull = unsigned long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vd = vector<double>;
using vvd = vector<vd>;
using vvvd = vector<vvd>;
using vs = vector<string>;
using vvs = vector<vs>;
using vc = vector<char>;
using vvc = vector<vc>;
using ii = pair<int,int>;
using vii = vector<ii>;
using vvii = vector<vii>;
using dd = pair<double, double>;
using vdd = vector<dd>;
using vvdd = vector<vdd>;
using Mii = map<int,int>;
using vMii = vector<Mii>;
using Si = set<int>;
using vSi = vector<Si>;
using vvSi = vector<vSi>;

#define fi first
#define se second
#define INF 1e9 + 5
#define mod(a,m) (a%m+m)%m
#define PB push_back
#define MP make_pair

int gcd(int a, int b) {
	if(b > a) swap(a, b);
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(){
//	cout.setf(ios::fixed);
//	cout.precision(4);
	int t;
	cin >> t;
	while(t--) {
		int a, b;
		cin >> a >> b;
		cout << (gcd(a, b) == 1? "Finite" : "Infinite") << endl;
	}
}


