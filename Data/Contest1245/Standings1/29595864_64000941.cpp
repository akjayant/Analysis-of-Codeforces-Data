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

int main(){
//	cout.setf(ios::fixed);
//	cout.precision(4);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a, b, c;
		cin >> a >> b >> c;
		string s;
		cin >> s;
		string t(n, '.');
		int win = 0;
		for (int i = 0; i < n; ++i) {
			if(s[i] == 'P' and c) {
				c--;
				t[i] = 'S';
				win++;
			}
			else if(s[i] == 'R' and b) {
				b--;
				t[i] = 'P';
				win++;
			}
			else if(s[i] == 'S' and a) {
				a--;
				t[i] = 'R';
				win++;
			}
		}
		if(2*win >= n) {
			cout << "YES" << endl;
			for (int i = 0; i < n; ++i) {
				if(t[i] == '.') {
					if(a) {
						t[i] = 'R';
						a--;
					}
					else if(b) {
						t[i] = 'P';
						b--;
					}
					else {
						t[i] = 'S';
						c--;
					}
				}
			}
			cout << t << endl;
		}
		else cout << "NO" << endl;
	}
}


