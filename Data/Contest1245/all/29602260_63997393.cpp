#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof a);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define per(i,a,b) for(int i = a; i >= b; i--)
#define __ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
typedef double db;
const db EPS = 1e-9;
using namespace std;

void dbg() {cout << "\n";}
template<typename T, typename... A> void dbg(T a, A... x) {cout << a << ' '; dbg(x...);}
#define logs(x...) {cout << #x << " -> "; dbg(x);}

ll gcd(ll a,ll b){
	return b == 0 ? a:gcd(b,a%b);
}

int main()
{
	int _; scanf("%d",&_);
	while(_--){
		int a,b; scanf("%d%d",&a,&b);
		int c = gcd(a,b);
		if(c == 1) printf("Finite\n");
		else printf("Infinite\n");
	}
	return 0;
}