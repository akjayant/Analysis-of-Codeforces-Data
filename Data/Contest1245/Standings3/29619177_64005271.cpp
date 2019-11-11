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

LL t, n, a, b, c;
string str;

int main() {
    FIO;
    cin >> t;
    while(t--) {
        cin >> n;
        cin >> a >> b >> c;
        cin >> str;
        string ans = str;
        LL r=0, p=0, s=0;
        for(char c: str){
            if(c == 'S') s++;
            if(c == 'R') r++;
            if(c == 'P') p++;
        }
        LL win = min(r, b)+min(p, c)+min(s, a);
        if(win < (n+1)/2) {
            cout << "NO" << endl;
            continue;
        }
        rep(i, 0, n-1) {
            if(str[i] == 'R' and b > 0) {
                ans[i] = 'P';
                b--;
            }
            else if(str[i] == 'P' and c > 0) {
                ans[i] = 'S';
                c--;
            }
            else if(str[i] == 'S' and a > 0) {
                ans[i] = 'R';
                a--;
            }
            else ans[i] = '?';
        }
        rep(i, 0, n-1) {
            if(ans[i] == '?') {
                if(a > 0) {
                    ans[i] = 'R';
                    a--;
                }
                else if(b > 0) {
                    ans[i] = 'P';
                    b--;
                }
                else if(c > 0) {
                    ans[i] = 'S';
                    c--;
                }
            }
        }
        cout << "YES\n" << ans << "\n";
    }
} 