#include <bits/stdc++.h>
#define FOR(i,a,b) for (long long i = a; i <= b; i++)
#define FORD(i,a,b) for (long long i = b; i >= a; i--)
#define reset(x,a) memset (x,a,sizeof(x))
#define task ""
using namespace std;
const long long MOD = 1e9 + 7;
const long long N = 300005;
string s;
long long dem1 = 0,dem2 = 0;
long long ans = 1;
long long fibo[100005];
main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    fibo[0] = 1;
    fibo[2] = 2;
    fibo[1] = 1;
    FOR(i,3,s.size()) fibo[i] = (fibo[i-1] + fibo[i-2])%MOD;
    FOR(i,0,s.size()-1){
        if (s[i] == 'm' || s[i] == 'w') {
            cout << 0;
            return 0;
        }
        if (s[i] == 'u') dem1++;
        if (s[i] == 'n') dem2++;
        if (s[i] != 'u') {
            ans = (ans*fibo[dem1])%MOD;
            dem1 = 0;
        }
        if (s[i] != 'n'){
            ans = (ans*fibo[dem2])%MOD;
            dem2 = 0;
        }
    }
    ans = (ans*fibo[dem2])%MOD;
    ans = (ans*fibo[dem1])%MOD;
    cout << ans;
    return 0;
}
