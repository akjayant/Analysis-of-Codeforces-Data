#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define allin(x, V) for(auto x : V)

#define endl '\n'
#define debug(vrb) {cerr << #vrb << ": " << vrb << endl;}
#define DEBUG(cnt) {cerr << #cnt << ": "; for(auto vrb : cnt) cerr << vrb << ", "; cerr << endl;}

typedef long long ll;
typedef long double ld;

typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

typedef vector<char> vc;
typedef vector<vc> vvc;
   
ll MOD = 1e9+7;

vvi mult(vvi A, vvi B) {
	vvi C = {{0, 0}, {0, 0}};
	for (int i=0; i<2; i++) {
		for (int j=0; j<2; j++) {
			for (int k=0; k<2; k++) {
				C[i][j] += A[i][k]*B[k][j];
			}
			C[i][j] %= MOD;
		}
	}
	return C;
}

vvi poww(vvi& A, ll b) {
	if (b == 1) return A;
	vvi S = poww(A, b/2);
	if (b%2 == 1) return mult(S, mult(S, A));
	else return mult(S, S);
}


ll fib(ll a) {
	vvi V = {{1, 1}, {1, 0}};

	V = poww(V, a);

	//cerr << V[0][0] << " " << V[0][1] << endl;
	//cerr << V[1][0] << " " << V[1][1] << endl;
	return (V[0][0])%MOD;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cout.setf(ios::fixed);
    //cout.precision(4);

    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    if (n > m) swap(n, m);

  	cout << (2*(fib(m) + fib(n)-1)%MOD + MOD)%MOD << endl;
}
