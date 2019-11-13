#define IOS ios::sync_with_stdio(false);
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 7;
const int M = 3e5 + 7;
const int INF = 1e8 + 7;
ll mod = 998244353;

int r, n, p, s, R, P, S;
char str[N], t[N];

int main(){
    IOS
    int kase;
    cin >> kase;
    while(kase --){
        R = P = S = 0;
        cin >> n >> r >> p >> s;
        cin >> str;
        for(int i = 0; str[i]; ++ i){
            if(str[i] == 'R'){
                ++ R;
            }else if(str[i] == 'P'){
                ++ P;
            }else if(str[i] == 'S'){
                ++ S;
            }
        }
        int win = min(p, R) + min(r, S) + min(s, P);
        if(win >= (n+1)/2){
            cout << "YES" << endl;
            memset(t, 0, sizeof(t));
            for(int i = 0; str[i]; ++ i){
                if(str[i] == 'R' && p){ --p; t[i] = 'P'; }
                else if(str[i] == 'S' && r){ --r; t[i]='R';}
                else if(str[i] == 'P' && s){ --s; t[i]='S';}
            }
            for(int i = 0; str[i]; ++ i){
                if(t[i] != 0) continue;
                if(p){ t[i] = 'P'; -- p;}
                else if(r){ t[i] = 'R'; -- r;}
                else { t[i] = 'S'; -- s;}
            }
            cout << t << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}