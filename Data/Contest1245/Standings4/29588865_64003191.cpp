#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const int MOD = 1e9 + 7;

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        int a,b,c;
        cin >> n;
        cin >> a >> b >> c;
        string s;
        cin >> s;
        int cnt = 0;
        string ans;
        REP(i,n){
            if(s[i] == 'R' && b > 0){
                ans.push_back('P');
                b--;
                cnt++;
            }else if(s[i] == 'P' && c > 0){
                ans.push_back('S');
                c--;
                cnt++;
            }else if(s[i] == 'S' && a > 0){
                ans.push_back('R');
                a--;
                cnt++;
            }else{
                ans.push_back('?');
            }
        }
        if(cnt < (n + 1) / 2){
            cout << "NO" << endl;
        }else{
            REP(i,n){
                if(ans[i] == '?'){
                    if(a > 0){
                        ans[i] = 'R';
                        a--;
                    }else if(b > 0){
                        ans[i] = 'P';
                        b--;
                    }else{
                        ans[i] = 'S';
                        c--;
                    }
                }
            }
            cout << "YES" << endl;
            cout << ans << endl;
        }
    }
    return 0;
}