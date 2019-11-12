#include <iostream>

#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

#define itn int
#define fro for
#define INF 0x7fffffff
#define lowbit(x) (x & (-x))
#define sze(s) (int)strlen(s)



typedef long long ll;
using namespace std;

/*----------------------------QUICK_READ----------------------------------------------*/
template <typename _t>
inline void read(_t &x){
    x = 0; _t fu = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') fu = - 1; ch = getchar();}
    while(ch >= '0' && ch <= '9'){
        x = (x << 3) + (x << 1) + (ch & 15);
        ch = getchar();
    }
    x *= fu ;
}
/*------------------------------------------------------------------------------------*/


//#define LOCAL
int main(){
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    int t; scanf("%d", &t);
    while(t--){
        itn a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        itn ans = 0;
        for(int i = 0; i <= a; i++){
            if(2 * i > b) break;
            
            itn cnt = 0;
            cnt += 3 * i;
            cnt += min(b - 2 * i, c / 2) * 3;
            ans = max(ans, cnt);
        }
        printf("%d\n", ans);
    }

    
    return 0;
}
