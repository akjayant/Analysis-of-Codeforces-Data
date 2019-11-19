#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 1e9 + 7;
inline int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
inline int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
inline int mul(int a, int b) {return 1ll * a * b % P;}
inline int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----
const int N = 101010;
int n;
ll m;
int a[N];
int main(){
	scanf("%d%lld", &n, &m);
	rep(i, 0, n) scanf("%d", a + i);
	sort(a, a + n);
	ll lcost = 1, rcost = 1;
	int mn = a[0], mx = a[n - 1];
	for(int l = 0, r = n - 1; l < r; ) {
		if(l + 1 <= n - r) {
			ll cl = (a[l + 1] - a[l]) * lcost;
			if(cl <= m) {
				mn = a[l + 1];
				m -= cl;
				lcost++;
				l++;
			}
			else {
				mn += m / (l + 1);
				break;
			}
		}
		else {
			ll cr = (a[r] - a[r - 1]) * rcost;
			if(cr <= m) {
				mx = a[r - 1];
				r--;
				m -= cr;
				rcost++;
			}
			else {
				mx -= m / (n - r);
				break;
			}
		}
	}
	printf("%d\n", mx - mn);
	return 0;
}

