#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ba back
#define ppb pop_back
#define eb emplace_back

#define sz(x) (int((x.size())))
#define all(x) (x).begin(),(x).end()

#define db(x)        cerr << #x << " = " << x << endl
#define db2(x, y)   {cerr << #x << " = " << x << "\t";  db(y);}
#define db3(x, y, z){cerr << #x << " = " << x << "\t";  db2(y,z);}

#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sl(a) scanf("%I64d", &a)
#define sll(a, b) scanf("%I64d%I64d", &a, &b)
#define slll(a, b, c) scanf("%I64d%I64d%I64d", &a, &b, &c)

#define bye exit(0)
#define FAST ios_base :: sync_with_stdio (false); cin.tie (NULL)

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

const ll MOD = 1e9 + 7;

ll add(ll x, ll y, ll CMOD=MOD){return (x+y+CMOD+CMOD)%CMOD;}
ll mult(ll x, ll y, ll CMOD=MOD){return add(x, 0)*add(y, 0) % CMOD;}

ll fast_expo(ll x, ll y, ll CMOD=MOD){
    if(x==0) return 0;
    if(y==0) return 1;
    ll ans = fast_expo(x, y/2, CMOD);
    ans = mult(ans, ans, CMOD);
    if(y&1) ans = mult(ans, x, CMOD);
    return ans;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll gen(ll x, ll y){
    if(x==y) return x;
    return x + rng()%(y-x+1);
}

const int TAM = 35;
const ll INF = LLONG_MAX/4;

vi v, w;
bool vis[TAM][3][3][3][3];
ll memo[TAM][3][3][3][3];

void toVector(vi &v, int x){
	v.clear();
	while(x > 0){
		v.emplace_back(x & 1);
		x >>= 1;
	}
}

ll dp(int pos, bool menorA, bool menorB, bool mayorA, bool mayorB){
	if(pos == -1){
		return 1;
	}
	if(vis[pos][menorA][menorB][mayorA][mayorB]) return memo[pos][menorA][menorB][mayorA][mayorB];
	ll ans = 0LL;
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			if((i ^ j) != i + j) continue;
			bool can = true;
			if(!menorA){
				if(i > w[pos]) can = false;
			}
			if(!menorB){
				if(j > w[pos]) can = false;
			}
			if(!mayorA){
				if(i < v[pos]) can = false;
			}
			if(!mayorB){
				if(j < v[pos]) can = false;
			}
			if(can){
				bool newMenorA = menorA or (i < w[pos]);
				bool newMenorB = menorB or (j < w[pos]);
				bool newMayorA = mayorA or (i > v[pos]);
				bool newMayorB = mayorB or (j > v[pos]);
				ans += dp(pos-1,newMenorA,newMenorB,newMayorA,newMayorB);
			}
		}
	}
	vis[pos][menorA][menorB][mayorA][mayorB] = true;
	return memo[pos][menorA][menorB][mayorA][mayorB] = ans;
}

int main(){
    int tc; si(tc);
	int a, b;
	while(tc--){
		sii(a,b);
		toVector(v,a);
		toVector(w,b);
		while(v.size() < w.size()) v.push_back(0);
		memset(vis,0,sizeof vis);
		ll ans = dp(v.size()-1,0,0,0,0);
		printf("%lld\n",ans);
	}

    return 0;
}
