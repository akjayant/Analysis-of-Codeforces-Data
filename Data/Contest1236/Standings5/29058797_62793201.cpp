#include    <bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define __unique(V) (V).resize(unique((V).begin(),(V).end())-(V).begin())
#define cntbit(X)   __builtin_popcount((X))
#define bit(S,i) (((S)>>(i))&1)
#define PI	acos(-1)
#define fi  first
#define se  second
#define LL  long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define eb  emplace_back
#define TASK "1236"
using namespace std;
const int mod = 1e9 + 7;
int n,m;
///--------------------------
int	pw(int A,int B){
    int tmp = 1;
    for( ; B ; A = 1LL * A * A % mod, B>>= 1)
		if (B & 1) tmp = 1LL * tmp * A % mod;
	return tmp;
}
///--------------------------
void    readf(){
    cin >> n >> m;
}
///--------------------------
void    solve(){
    cout << (pw(pw(2,m) - 1,n) + mod) % mod;
}
///--------------------------
int     main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #ifdef TLH2203
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    #endif // TLH2203
    readf();
    solve();
}




