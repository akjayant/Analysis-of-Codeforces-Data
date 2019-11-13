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
        int a, b;
        cin >> a >> b;
        cout << (__gcd(a, b) == 1 ? "Finite" : "Infinite");
        cout << "\n";
        read_data();
        solve();
    }
}
