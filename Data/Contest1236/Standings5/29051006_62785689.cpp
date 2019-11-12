#include <iostream>
#include <stdio.h>

using namespace std;

#define FOR(i,l,r) for(int i = l; i <= r; ++i)
#define REP(i,l,r) for(int i = l; i < r; ++i)

const int maxN = 1e5 + 123;

int T,a,b,c;

int main(){
    //freopen("A.INP","r",stdin);
    //freopen("A.OUT","w",stdout);

    cin >> T;
    FOR(i,1,T){
        cin >> a >> b >> c;
        int y = min(c/2,b);
        b -= y;
        int x = min(a,b/2);
        cout << 3 * y + 3 *x << endl;
    }
    return 0;
}