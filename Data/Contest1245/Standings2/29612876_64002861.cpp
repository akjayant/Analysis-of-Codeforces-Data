#include <bits/stdc++.h>
#define E 0.000000000001
using namespace std;
 
typedef long long ll;
typedef pair <ll, ll> pll;
 
int main() {
    ios_base:: sync_with_stdio(false);
    ll q;
    cin >> q;
    while(q--) {
        ll n, a, b, c;
        cin >> n >> a >> b >> c;
        string s;
        cin >> s;
        string answ = s;
        ll cnt = n;
        for(ll i = 0; i < n ; i++) {
            if(s[i] == 'R' && b > 0) {
                b--;
                answ[i] = 'P';
            }
            else if(s[i] == 'P' && c > 0) {
                c--;
                answ[i] = 'S';
            }
            else if(s[i] == 'S' && a > 0) {
                a--;
                answ[i] = 'R';
            }
            else {
                answ[i] = '*';
                cnt--;
            }
        }
        if(cnt * 2 >= n) {
            cout << "YES\n";
            for(ll i = 0; i < n; i++) {
                if(answ[i] == '*') {
                    if(a > 0) {
                        cout << 'R';
                        a--;
                    }
                    else if(b > 0) {
                        cout << 'P';
                        b--;
                    }
                    else cout << 'S';
                    
                }
                else cout << answ[i];
            }
            cout << endl;
        }
        else cout << "NO\n";
    }
}
 