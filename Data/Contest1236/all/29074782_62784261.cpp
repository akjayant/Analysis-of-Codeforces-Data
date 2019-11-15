#include <bits/stdc++.h>
using namespace std;
#define IO                 \
	ios::sync_with_stdio(0); \
cin.tie(0);              \
cout.tie(0);
#define forn(i, n) for (int i = 0; i < n; i++)
#define forse(i, s, e) for (int i = s; i < e; i++)
#define pb push_back
#define pf push_front
#define rb pop_back
#define rf pop_front
#define mp make_pair
#define all(vec) vec.begin(), vec.end()
#define getcurrtime() \
	cerr << "Time = " << ((double)clock() / CLOCKS_PER_SEC) << endl

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> Matrix;
const int sqr = 500;
ll P = 1e9 + 7;
const int arrn = 1e5 + 3;
const int arrn2 = 5e3 + 3;

void solve() {
	int a,b,c;
	cin >> a >> b >> c;
	int out=INT_MIN;
	forn(i,a+1){
		forn(j,b+1){
			if(2*j<=c){
				if(2*i<=b-j){
					out=max(out,3*i+3*j);
				}
			}
		}
	}
	cout << out << '\n';
}
int main() {
  IO;
  int T;
	cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
