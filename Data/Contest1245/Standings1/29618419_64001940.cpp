#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define iter(it,c) for(auto it = (c).begin(); it != (c).end();++it)
#define pb push_back
#define fs first
#define sc second
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

const int INF = ~(1<<31);
const double pi = acos(-1);
const double EPS = 1e-9;
typedef unsigned long long ull;

template <class T> T smod(T a, T b) {
  return (a % b + b) % b; }

void sv() {
    int n;
    cin >> n;
    int a,b,c;
    cin >> a >> b >> c;
    string s = "";
    int _a=0,_b=0,_c=0;
    cin >> s;
    rep(i,0,size(s)) {
        if(s[i] == 'R') _a++;
        else if(s[i] == 'P') _b++;
        else _c++;
    }
    int sm = min(_a, b)+min(_c, a)+min(_b, c);
    if(sm >= (n+1)/2) {
        cout << "YES" << endl;
        string o = "";
        rep(i,0,size(s)) o += "1";
        rep(i,0,size(s)) {
            if(s[i] == 'R') {
                if(b != 0) {
                    o[i] = 'P';
                    b--;
                }
            }
        }
        rep(i,0,size(s)) {
            if(s[i] == 'P') {
                if(c != 0) {
                    o[i] = 'S';
                    c--;
                }
            }
        }
        rep(i,0,size(s)) {
            if(s[i] == 'S') {
                if(a != 0) {
                    o[i] = 'R';
                    a--;
                }
            }
        }
        rep(i,0,size(s)) {
            if(o[i] == '1') {
                if(a != 0) {
                    o[i] = 'R';
                    a--;
                } else if(c != 0) {
                    o[i] = 'S';
                    c--;
                } else if(b != 0) {
                    o[i] = 'P';
                    b--;
                }
            }
        }
        cout << o << endl;
    }
    else cout << "NO" << endl;
}

int main() {
    cin.sync_with_stdio(false);
    int t;
    cin >> t;
    rep(i,0,t) {
        sv();
    }
    return 0;
}


