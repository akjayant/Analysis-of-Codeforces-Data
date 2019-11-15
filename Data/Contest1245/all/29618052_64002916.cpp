#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = b; i >= a; i--)
#define f first
#define s second
#define reset(x,a) memset (x,a,sizeof(x))
#define task ""
using namespace std;
const int MOD = 1e9 + 7;
const int N = 300005;
int t,n,a,b,c,times;
string s;
string ans;
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--){
        times = 0;
        cin >> n >> a >> b >> c;
        cin >> s;
        ans = s;
        if (n%2 == 1) n = n/2 + 1;
        else n = n/2;
        FOR(i,0,s.size()-1){
            ans[i] = '0';
            if (s[i] == 'S' && a > 0) a--,times ++,ans[i] = 'R';
            if (s[i] == 'R' && b > 0) b--,times ++,ans[i] = 'P';
            if (s[i] == 'P' && c > 0) c--,times ++,ans[i] = 'S';
        }
        if (times >= n) {
            cout << "YES" << endl;
            FOR(i,0,ans.size()-1){
                if (ans[i] == '0'){
                    if (a > 0) ans[i] = 'R',a--;
                    else if (b > 0) ans[i] = 'P',b--;
                    else if (c > 0) ans[i] = 'S',c--;
                }
            }
            cout << ans << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}
