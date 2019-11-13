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

int main() {
    int z;
    scanf("%d", &z);
    FOR(i,1,z) {
        int n, r, p, s;
        string xs;
        cin >> n >> r >> p >> s;
        cin >> xs;


        string ys(n, '_');
        int wins = 0;
        FORW(i,0,n) {
            if (xs[i] == 'S' and r > 0) {
                --r;
                ys[i] = 'R';
                ++wins;
            }
            if (xs[i] == 'R' and p > 0) {
                --p;
                ys[i] = 'P';
                ++wins;
            }
            if (xs[i] == 'P' and s > 0) {
                --s;
                ys[i] = 'S';
                ++wins;
            }
        }
        FORW(i,0,n) {
            if (ys[i] == '_' and r > 0) { r--; ys[i] = 'R'; };
            if (ys[i] == '_' and p > 0) { p--; ys[i] = 'P'; };
            if (ys[i] == '_' and s > 0) { s--; ys[i] = 'S'; };
        }
        if (wins < (n+1)/2) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl << ys << endl;
    }
}
