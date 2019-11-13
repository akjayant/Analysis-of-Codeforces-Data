#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#define D(a) cerr << #a << " = " << a << endl
#else
	#define D(a)
	#define cerr false && cerr
#endif
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)
#define all(a) a.begin(),a.end()
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int M = 1e9 + 7;

int main() {
	fastio;
	
    string s; cin >> s;
    int n = si(s);

    vi dp(n + 1);
    dp[0] = 1, dp[1] = 1; forsn(i, 2, n + 1) dp[i] = (dp[i - 1] + dp[i - 2]) % M;

    int ans = 1;
    forn(i, n) 
        if (s[i] == 'u' || s[i] == 'n') {
            int j = i; while (j + 1 < n && s[j + 1] == s[i]) j++;

            ans = ((ll) ans * dp[j - i + 1]) % M;

            i = j;
        }
        else if (s[i] == 'w' || s[i] == 'm') ans = 0;

    cout << ans << endl;
	
	return 0;
}
