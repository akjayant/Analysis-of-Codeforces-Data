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

void solve(int n){
    std::vector<pii> A;
    REP(i, n){
        if(str[0][i] == str[1][i]) continue;
        for(int j = i + 1; j < n; ++j) if(str[0][i] == str[0][j]){
            std::swap(str[1][i], str[0][j]);
            A.push_back({j, i}); break;
        }
        if(str[0][i] == str[1][i]) continue;
        for(int j = i + 1; j < n; ++j) if(str[0][i] == str[1][j]){
            std::swap(str[0][j], str[1][j]); A.push_back({j, j});
            std::swap(str[1][i], str[0][j]); A.push_back({j, i});
            break;
        }
        if(str[0][i] != str[1][i]){
            puts("No"); return;
        }
    }
    const int m = A.size();
    printf("Yes\n%d\n", m);
    REP(i, m) printf("%d %d\n", A[i].first + 1, A[i].second + 1);
}

int main(void){
    int Q; scanf("%d", &Q);
    while(Q--){
        int n; scanf("%d", &n);
        scanf("%s%s", str[0], str[1]);
        solve(n);
    }


  
    return 0;
}