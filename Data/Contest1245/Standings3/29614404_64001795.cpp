#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define X first
#define Y second
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FOD(i, a, b) for(int i = a; i >= b; i--)

typedef long long ll;
typedef pair <int, int> ii;

const int N = 410;
const int INF = 1e9;

int main(){
    int t, n, a, b, c;
    int a1, b1, c1;
    string s;
    cin >> t;
    while (t--){
        cin >> n >> a >> b >> c;
        cin >> s;
        int cnt = 0;
        string ans;
        for(char ch : s){
            if (ch == 'R'){
                if (b > 0){
                    b--;
                    cnt++;
                    ans = ans + 'P';
                }
                else{
                    ans = ans + '*';
                }
            }
            if (ch == 'P'){
                if (c > 0){
                    c--;
                    cnt++;
                    ans = ans + 'S';
                }
                else{
                    ans = ans + '*';
                }
            }
            if (ch == 'S'){
                if (a > 0){
                    a--;
                    cnt++;
                    ans = ans + 'R';
                }
                else{
                    ans = ans + '*';
                }
            }
        }
        if (cnt >= (n + 1) / 2){
            cout << "YES" << endl;
            for(char &ch : ans) if (ch == '*'){
                if (a > 0)
                    ch = 'R', a--;
                else if (b > 0)
                    ch = 'P', b--;
                else
                    ch = 'S', c--;
            }
            cout << ans << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
