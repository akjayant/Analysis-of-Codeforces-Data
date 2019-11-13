#include<bits/stdc++.h>
 
using namespace std;
 
#define LL long long
#define pb push_back
#define pLL pair<LL,LL>
#define ff first
#define ss second
#define rep(i,a,b) for(LL i=a;i<=b;++i)
#define repb(i,a,b) for(LL i=a;i>=b;--i)
#define ld double
#define mp make_pair
#define vLL vector<LL>
#define vpLL vector<pLL>
#define vld vector<ld>
#define pld pair<ld,ld>
#define vpld vector<pld>
#define SLL set<LL>
#define SpLL set<pLL>
#define FIO ios::sync_with_stdio(false)
#define mod 1000000007

string s;
LL fib[100005];

int main() {
    FIO;
    cin >> s;
    fib[1] = 1;
    fib[2] = 2;
    for(char c: s) {
        if(c == 'm' or c == 'w') {
            cout << 0;
            return 0;
        }
    }
    s += '?';
    LL ans = 1, i = 1, n = s.size(), cnt = 0;
    rep(i,3,n+2) {
        fib[i] = (fib[i-1]+fib[i-2]) % mod;
    }
    if(s[0] == 'n' or s[0] == 'u') cnt ++;
    for(;i < n; i++) {
        if(s[i] == s[i-1]) cnt++;
        else {
            if(s[i-1] == 'n' or s[i-1] == 'u') {
                ans = (ans*fib[cnt]) % mod;
            }
            cnt = 1;
        }
    }
    cout << ans << endl;
}