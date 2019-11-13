#include<bits/stdc++.h>
using namespace std;
 
#define END '\n'
#define int long long
#define pb push_back
#define pii pair<int, int>
#define loop(i, a, b) for(int i = (a); i < (b); i++)
#define loopb(i, b, a) for(int i = (b); i > (a); --i)
 
string alpha = "abcdefghijklmnopqrstuvwxyz";
const int mod = 1e9+7;
const int inf = 2e18+5;
const int nax = 101010;
//



signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("fin.txt", "r", stdin);
        freopen("fout.txt", "w", stdout);
    #endif
    //

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a, b, c; cin >> a >> b >> c; //rps

        string s; cin >> s;
        vector<char> res(n, 'A');
        int cnt = 0;

        loop(i, 0, n){
            if(s[i] == 'R' && b > 0){
                b--;
                res[i] = 'P';
                cnt++;
            }
            if(s[i] == 'P' && c > 0){
                c--;
                res[i] = 'S';
                cnt++;
            }
            if(s[i] == 'S' && a > 0){
                a--;
                res[i] = 'R';
                cnt++;
            }
        }

        loop(i, 0, n){
            if(res[i] == 'A'){
                if(a > 0){
                    res[i] = 'R';
                    a--;
                }
                else if(b > 0){
                    res[i] = 'P';
                    b--;
                }
                else if(c > 0){
                    res[i] = 'S';
                    c--;
                }
            }
        }
        int W = n/2 + n%2;
        if(cnt >= W){
            cout << "YES\n";
            for(auto x : res) cout << x;
            cout << END;
        }else{
            cout << "NO\n";
        }

    }



    return 0;
}