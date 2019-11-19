#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <cmath>
#include <string>
#include <set>
#include <complex>
#include <cstdio>
#include <cstring>
#include <stack>
#include <iomanip>
#include <bitset>
#include <typeinfo>
#include <random>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int t;
int n, m;
long long oneji, oneou, tji, tou;

int main(){
    scanf("%d", &t);
    while(t--){
        oneji = 0, oneou = 0, tji = tou = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            int x;
            scanf("%d", &x);
            if(x % 2 == 0) oneou++;
            else oneji++;
        }
        scanf("%d", &m);
        for(int i = 1; i <= m; i++){
            int x;
            scanf("%d", &x);
            if(x % 2 == 0) tou++;
            else tji++;
        }
        printf("%lld\n", oneji * tji + oneou * tou);
    }
    return 0;
}