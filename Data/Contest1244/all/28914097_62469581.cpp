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
const int N = 2020;
int T, n;
char s[N];
int main(){
	scanf("%d", &T);
	rep(cas, 0, T) {
		scanf("%d%s", &n, s);
		int l = -1, r = -1;
		rep(i, 0, n) if(s[i] == '1') {
			if(l == -1) l = i;
			r = i;
		}
		int ans = 0;
		if(l == -1) ans = n;
		else {
			ans = max(2 * (n - l), 2 * (r - 0 + 1));
		}
		printf("%d\n", ans);
	}
	return 0;
}
