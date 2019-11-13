#include <iostream>
#include <limits>
#include <cfenv>
#include <cmath>
#include <algorithm>
#include <array>
#include <bitset>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include <tuple>
#include <queue>
#include <vector>
#include <cmath>
#include <random>
#include <math.h>
#include <list>
#include <random>
#include <functional>


#define FOR(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define REP(i, n) FOR(i, 0, n)
#define rREP(i, n) for(int (i) = (n) - 1; (i) >= 0; --(i))
#define ALL(TheArray) TheArray.begin(), TheArray.end()

using lli = long long int;
using pii = std::pair<int, int>;

template <class T> inline bool chmax(T& a, T b){
    if(a < b){a = b; return true;}
    return false;
}
template <class T> inline bool chmin(T& a, T b){
    if(a > b){a = b; return true;}
    return false;
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


constexpr int N = 1000;
std::array<int, N+1> A;


int main(void){
    int Q; scanf("%d", &Q);
    while(Q--){
        int n; scanf("%d", &n);
        std::fill(A.begin(), A.end(), 0); A[0] = n;
        REP(i, n){ int k; scanf("%d", &k); A[k+1]--;}
        REP(i, n) A[i+1] += A[i];
        int res = 0;
        while(res + 1 <= n){
            if(A[res+1] >= res + 1 ) res++;
            else break;
        }
        printf("%d\n", res);
    }


  
    return 0;
}