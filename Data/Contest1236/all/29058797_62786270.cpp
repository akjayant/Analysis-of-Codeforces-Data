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
int F[105][105][105];
int a,b,c;
///--------------------------
void    readf(){
	cin >> a >> b >> c;
}
///--------------------------
int	f(int x,int y,int z){
	int &rs = F[x][y][z];
	if (rs != -1) return rs;
    rs = 0;
    if (x > 0 && y > 1) rs = max(rs, 3 + f(x - 1,y - 2,z));
    if (y > 0 && z > 1) rs = max(rs, 3 + f(x,y - 1,z - 2));
    return rs;
}
///--------------------------
void    solve(){
    cout << f(a,b,c) << '\n';
}
///--------------------------
int     main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #ifdef TLH2203
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    #endif // TLH2203
    memset(F,-1,sizeof(F));
    int T;
    cin >> T;
    while (T--){
		readf();
		solve();
    }
}




