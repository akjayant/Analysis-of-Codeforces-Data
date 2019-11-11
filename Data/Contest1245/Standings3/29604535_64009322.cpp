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
const LL MOD = 1e9 + 7;

int N;
string s;
LL F[maxN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    //

    cin >> s;
    N = s.size();
    s = " " + s;
    
    FOR(i,1,N){
        if(s[i] == 'w' || s[i] == 'm'){
            cout << 0;
            return 0;
        }
    }
    //
    F[0] = 1;
    F[1] = 1;
    FOR(i,2,N){
        F[i] = F[i - 1];
        if(s[i] == s[i - 1] && (s[i] == 'n' || s[i] == 'u')) F[i] += F[i - 2];
        F[i] %= MOD;
    }

    cout << F[N];

    return 0;
}