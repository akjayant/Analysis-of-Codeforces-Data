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
 
const int MAXN = 54;
const int MOD = 1e9+7;
const int INF = 1e9+1;

int N;
char A[MAXN], B[MAXN];
int C[26];

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
        cin >> A >> B;
        fori(i,26) C[i] = 0;
        fori(i,N) {
            C[A[i]-'a']++;
            C[B[i]-'a']++;
        }
        int ok = 1;
        fori(i,26) if(C[i]%2) ok = 0;
        if(!ok) cout << "No\n";
        else {
            cout << "Yes\n";
            vector<pii> ans;
            fori(i, N) {
                if(A[i] != B[i]) {
                    int found = 0;
                    fore(k,i+1,N-1) {
                        if(B[i] == B[k]) {
                            found = 1;
                            swap(A[i],B[k]);
                            ans.eb(i,k);
                            break;
                        }
                    }

                    if(!found) {
                        found = 0;
                        fore(k,i+1,N-1) {
                            if(B[i] == A[k]) {
                                found = 1;
                                swap(A[k],B[k]);
                                ans.eb(k,k);
                                swap(A[i],B[k]);
                                ans.eb(i,k);
                                break;
                            }
                        }
                        assert(found);
                    }
                }
            }

            cout << ans.size() << '\n';
            for(auto p: ans) cout << p.fi+1 << ' ' << p.se+1 << '\n';
        }
    }
    return 0;
}

