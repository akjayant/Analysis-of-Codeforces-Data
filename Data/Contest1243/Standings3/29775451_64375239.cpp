#include <bits/stdc++.h>
 
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
 
#define pb push_back 
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second 
#define debug(x)  do{cerr<<#x<<": "<<x<<"\n";}while(0)
#define debugv(x) do{cerr<<#x<<": ";for(auto&e: (x))cerr<<e<<" ";cerr<<"\n";}while(0)
#define fori(i, n) for (int i = 0; i < (int)(n); ++i)
#define forn(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n); i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define RETURN(x) do{cout << x << '\n'; return 0;}while(0)
#define FIRSTWIN do{cout << "Monocarp\n"; return 0;}while(0)
#define SECONDWIN do{cout << "Bicarp\n"; return 0;}while(0)
 
const int MAXN = 1e5+5;
const int MOD = 1e9+7;
const int INF = 1e9+1;

int N;
int A[1001];

int main() {
#ifdef OJ
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q; cin >> q;
    while(q--) {
        cin >> N;
        fori(i,N) A[i+1] = 0;
        fori(i,N) {
            int a; cin >> a;
            A[a]++;
        }

        int mx = 0;
        int c = 0;
        for(int i = N; i > 0; i--) {
            c += A[i];
            mx = max(mx, min(c,i));
        }

        cout << mx << '\n';
    }
    return 0;
}

