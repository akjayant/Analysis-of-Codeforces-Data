#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;  
typedef pair<int,int> ii;  
typedef vector<ii> vii;  
typedef list<int> li;  
typedef unordered_map<int,int> mii;

#define ll long long
#define rep(i,n) for (int i = 0; i < (n); i++)  
#define rrep(i,n) for (int i = (n)-1; i >= 0; i--)
#define rap(i,a,n) for (int i = a; i < (n); i++) 
#define rrap(i,n,a) for (int i = (n)-1; i >= a; i--) 

vi al, bo;

int main() {
    ios_base::sync_with_stdio(false);
    int t,a,b,c,n,count;
    string s;
    cin >> t;
    rep(tt,t) {
        count = 0;
        cin >> n;
        cin >> a >> b >> c;
        cin >> s;
        al.assign(n,0);
        bo.resize(n);
        rep(i,n) {
            if (s[i] == 'R') bo[i] = 1;
            else if (s[i] == 'P') bo[i] = 2;
            else bo[i] = 3;
        }
        rep(i,n) {
            if (bo[i] == 1 && b > 0) {
                al[i] = 2;
                b--;
                count++;
                continue;
            }
            else if (bo[i] == 2 && c > 0) {
                al[i] = 3;
                c--;
                count++;
                continue;
            }
            else if (bo[i] == 3 && a > 0) {
                al[i] = 1;
                a--;
                count++;
                continue;
            }
        }
        if (count*2 < n) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        rep(i,n) {
            if (al[i] == 0) {
                if (a > 0) {
                    al[i] = 1;
                    a--;
                }
                else if (b > 0) {
                    al[i] = 2;
                    b--;
                }
                else {
                    al[i] = 3;
                    c--;
                }
            }
        }
        rep(i,n) {
            if (al[i] == 1) cout << 'R';
            else if (al[i] == 2) cout << 'P';
            else cout << 'S';
        }
        cout << '\n';
    }
    return 0;

    //compile: g++ -std=c++14 -O2 -Wall NAME.cpp -o NAME
}