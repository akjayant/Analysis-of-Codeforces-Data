#include<bits/stdc++.h>

using namespace std;
#define REPP(i,a,b,c) for(int i=a; i<=b; i+=c)
#define REP(i,a,b) REPP(i,a,b,1)
#define REVV(i,a,b,c) for(int i=a; i>=b; i-=c)
#define REV(i,a,b) REVV(i,a,b,1)
#define FOR(i,a) REP(i,0,(int)a-1)
#define FORD(i,a) REV(i,(int)a-1,0)
#define PB push_back
#define POB pop_back
#define FI first
#define SE second
#define MP make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair < int , int > pii;
typedef vector < int > vi;
typedef vector < pii > vii;
typedef vector < ll > vl;
typedef pair < ll , ll > pll;

const double PI = acos(-1);
const double EPS = 1e-9;
const ll MOD = 1e9 + 7;
const int INF = 1e9;
	

ll addMod(ll a, ll b){
	if(a + b >= MOD) return a + b - MOD;
	return a + b;
}

ll mulMod(ll a, ll b){
	return (a*b)%MOD;
}

ll fast(ll a, ll b){
	if(b == 0) return 1;
	ll tmp = fast(a,b/2);
	tmp = mulMod(tmp,tmp);
	if(b%2 == 1) tmp = mulMod(tmp,a);
	return tmp;
}

ll GCD(ll a, ll b){
	if(a > b) return GCD(b,a);
	if(a == 0) return b;
	return GCD(b%a,a);
}

#define getc getchar
template<typename T>
T getnum(){
	int sign = 1;
	T ret = 0;
	char c;

	do{
		c = getc();
	}while(c == ' ' || c == '\n');
	if(c == '-')sign = -1;
	else ret = c-'0';
	while(1){
		c = getc();
		if(c < '0' || c > '9')break;
		ret = 10*ret + c-'0';
	}
	return sign * ret;
}

inline void ini(int& x){
	x = getnum<int>();
}

//////////////////////////////////////////////

int n;
vector < int > ans[305];

void solve(){
	int num = 0;
	REP(i,1,n){
		if(i % 2 == 1){
			REP(j,1,n){
				ans[j].PB(++num);
			}
		}
		else{
			REV(j,n,1){
				ans[j].PB(++num);
			}
		}
	}
}

int main(){
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	solve();
	REP(i,1,n){
		FOR(j,n){
			if(j > 0) cout << " ";
			cout << ans[i][j];
		}
		cout << endl;
	}
	return 0;
}
