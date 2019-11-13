#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

#define LL long long 
#define FOR(i,l,r) for(int i = l; i <= r; ++i)
#define REP(i,l,r) for(int i = l; i < r; ++i)
#define FORD(i,r,l) for(int i = r; i >= l; --i)
#define REPD(i,r,l) for(int i = r; i > l; --i)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second

const int maxN = 2e5 + 11;
const LL oo = 1e17 + 11;

int T,a,b;

int gcd(int x,int y){
    if(y == 0) return x;
    return gcd(y,x % y);
}
void testcase(){
    cin >> a >> b;
    if(gcd(a,b) == 1) cout << "Finite"<<endl;
    else cout << "Infinite" << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    //

    cin >> T;
    FOR(i,1,T) testcase();

    return 0;
}