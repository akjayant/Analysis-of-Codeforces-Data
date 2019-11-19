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
#define TASK "1245F"
using namespace std;
int a,b;
LL F[35][2][2][2][2];
deque <int> A,B;
///--------------------------
void    readf(){
    cin >> a >> b;
}
///--------------------------
LL  f(int i,bool okxL,bool okyL,bool okxR,bool okyR){
	//	cerr << i <<' ' << okxL <<' ' << okyL << " cm\n";
    LL &rs = F[i][okxL][okyL][okxR][okyR];
    if (rs != -1) return rs;
    if (i == B.size()) return (rs = 1);
    rs = 0;
    for(int x = min(1 - okxL, A[i]); x <= max(0 + okxR,B[i]); ++x)
    for(int y = min(1 - okyL, A[i]); y <= max(0 + okyR,B[i]); ++y)
		if ((x & y) == 0){
		cerr << i <<' '<<x << ' '<< y << '\n';
        rs += f(i + 1,okxL || (x > A[i]), okyL || (y > A[i]), okxR || (x < B[i]),okyR || (y < B[i]));
    }
	return rs;
}
///--------------------------
void    solve(){
	memset(F,-1,sizeof(F));
	A.clear(); B.clear();
    while (b > 0) B.push_front(b & 1), b >>= 1;
    fo(i,1,B.size()) A.push_front(a & 1), a >>= 1;
    cout <<  f(0,0,0,0,0) << '\n';
}
///--------------------------
int     main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #ifdef TLH2203
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    #endif // TLH2203
    int T;
    cin >> T;
    while (T--){
		readf();
		solve();
    }
}




