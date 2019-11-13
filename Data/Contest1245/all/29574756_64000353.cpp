#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<vector>
#include<map>
    
#define fst first
#define sc second
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,root<<1
#define rson mid+1,r,root<<1|1
#define lc root<<1
#define rc root<<1|1
#define lowbit(x) ((x)&(-x)) 

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PI;
typedef pair<ll,ll> PLL;

const db eps = 1e-6;
const int mod = 1e9+7;
const int maxn = 2e6+100;
const int maxm = 2e6+100;
const int inf = 0x3f3f3f3f;
const db pi = acos(-1.0);

int main() {
    int t;
    scanf("%d", &t);
    while(t--){
        int x,y;
        scanf("%d %d", &x, &y);
        if(__gcd(x,y)==1){
            printf("Finite\n");
        }
        else {
            printf("Infinite\n");
        }
    }
    return 0;
}