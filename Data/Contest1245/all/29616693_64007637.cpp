#include<bits/stdc++.h>
#define ALL(X)        X.begin(),X.end()
#define FOR(I,A,B)    for(int I = A; (I) <= (B); (I)++)
#define FORW(I,A,B)   for(int I = A; (I) < (B);  (I)++)
#define FORD(I,A,B)   for(int I = A; (I) >= (B); (I)--)
#define CLEAR(X)      memset(X,0,sizeof(X))
#define SIZE(X)       int(X.size())
#define CONTAINS(A,X) (A.find(X) != A.end())
#define PB            push_back
#define MP            make_pair
#define X             first
#define Y             second
using namespace std;

typedef signed long long slong;
typedef long double ldouble;
const slong INF = 1000000100;
const ldouble EPS = 1e-9;

void read_data() {

}

void solve() {

}

slong MOD = 1000000007;

const int MAXN = 1000100;
slong F[MAXN];

int main() {
    F[0] = 1;
    F[1] = 1;
    F[2] = 2;
    FORW(i,3,MAXN) F[i] = (F[i-1] + F[i-2]) % MOD;
    string s;
    cin >> s;
    s += "%";
    int streak = 0;
    char last_char = '#';
    slong r = 1;
    for (char c: s) {
        if (c == 'm' or c == 'w') {
            r = 0;
            break;
        }
        if (c == 'n' or c == 'u') {
            if (c == last_char) {
                streak++;
            } else {
                r *= F[streak];
                r %= MOD;
                streak = 1;
            }
        } else {
            r *= F[streak];
            r %= MOD;
            streak = 1;
        }
        last_char = c;
    }
    cout << r << endl;
}
