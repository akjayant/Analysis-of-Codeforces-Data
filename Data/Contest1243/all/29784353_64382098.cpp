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


constexpr int N = 1e5+10;
char str[2][N];


int main(void){
    int Q; scanf("%d", &Q);
    while(Q--){
        int n; scanf("%d", &n);
        scanf("%s%s", str[0], str[1]);
        int cnt = 0;
        int a = -1, b = -1;
        REP(i, n) if(str[0][i] != str[1][i]){
            cnt++; if(cnt > 2) break;
            if(cnt == 1) a = i;
            else b = i;
        }
        if(cnt > 2 or cnt == 1) puts("NO");
        else{
            if(str[0][a] == str[0][b] and str[1][a] == str[1][b]) puts("YES");
            else puts("NO");
        }
    }


  
    return 0;
}