#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <list>
#include <map>
#include <bitset>
#include <queue>
#include <functional>  
#include <numeric>      
#include <assert.h>

#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (auto i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piii;
typedef pair<pll, ll>plll;
typedef pair<int, ll>pil;

long long gcd(long long a, long long b) {
	long long r, i;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}


int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a, b, c;
		cin >> a >> b >> c;
		string s;
		cin >> s;

		int reqWin = (n + 1) / 2;

		bool canWin = false;
		int wins = 0;

		string temp(n, '.');
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'R' && b > 0) {
				b--;
				temp[i] = 'P';
				wins++;
			}
			else if (s[i] == 'P' && c > 0) {
				c--;
				temp[i] = 'S';
				wins++;
			}
			else if (s[i] == 'S' && a > 0) {
				a--;
				temp[i] = 'R';
				wins++;
			}
		}

		if (wins < reqWin) {
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
			for (int i = 0; i < s.size(); i++) {
				if (temp[i] == '.') {
					if (a > 0) {
						a--;
						temp[i] = 'R';
					}
					else if (b > 0) {
						b--;
						temp[i] = 'P';
					}
					else {
						c--;
						temp[i] = 'S';
					}
				}
			}
			cout << temp << "\n";

		}
	}

	
}