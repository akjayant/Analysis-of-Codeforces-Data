#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define sc(a) scanf("%d", &a)
#define sc2(a, b) sc(a), sc(b)
#define pri(x) printf("%d\n", x)
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	ll n;
	cin >> n;
	set<ll> primes;
	ll curr = n;
	for(ll i = 2; i*i <= n; i++){
		while(curr % i == 0){
			curr /= i;
			primes.insert(i);
		}
	}
	if(curr > 1) primes.insert(curr);
	if(primes.size() == 1){
		cout << *primes.begin() << endl;
	}
	else cout << 1 << endl;
	exit(0);
}
