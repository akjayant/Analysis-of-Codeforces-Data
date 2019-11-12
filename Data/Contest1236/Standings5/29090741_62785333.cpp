#include<bits/stdc++.h>
#define ri register int
#define forn(i, n) for(int i = 1; i <= (n); i++)
typedef long long ll;
using namespace std;
/* Template_In_Programming_Contest */

void rd(int& u) {scanf("%d", &u);}
void rd2(int& u, int& v) {scanf("%d%d", &u, &v);}
void rd3(int& u, int& v, int& w) {scanf("%d%d%d", &u, &v, &w);}
void ptn(int u) {printf("%d\n", u);}
void pte(int u) {printf("%d ", u);}

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int , int> pii;
typedef pair <ll , ll> pll;
typedef vector <int> vi;

int t, a, b, c;
int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> t;
	while(t--) {
		cin >> a >> b >> c;
		
		int ans = 0;
		for(int o = 0; o <= 100; o++) {
			if(o * 2 > b) continue;
			
			int ca = a, cb = b, cc = c;
			int no = o, cans = 0;
			while(no--) {
				if(ca < 1 || cb < 2) break;
				cans += 3; 
				ca--; cb -= 2; 
			}
			while(1) {
				if(cb < 1 || cc < 2) break;
				cans += 3;
				cb--; cc -= 2;
			}
			ans = max(ans, cans);
		}
		cout << ans << endl;
	}
	return 0;
}
