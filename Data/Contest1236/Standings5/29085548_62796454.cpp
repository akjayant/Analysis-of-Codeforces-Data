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


const itn maxn = 305;
int n;
itn a[maxn][maxn];

void ini(){
    int flag = 0;
    int number = 1;
    for(int i = 0; i < n; i++){
        if(!flag){
            flag = !flag;
            for(int j = 0; j < n; j++) a[i][j] = number++;
        }
        else{
            flag = !flag;
            for(int j = n - 1; j >= 0; j--) a[i][j] = number++;
        }
    }
}

//#define LOCAL
int main(){
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &n); ini();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) printf("%d ", a[j][i]);
        printf("\n");
    }
    return 0;
}
