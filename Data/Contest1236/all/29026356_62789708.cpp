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
#include<functional>
#include<bitset>
    
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
const int maxn = 5e5+100;
const int maxm = 2e6+100;
const int inf = 0x3f3f3f3f;
const db pi = acos(-1.0);

int a,b,c;
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int ans = 0;
        scanf("%d %d %d" ,&a, &b, &c);
        for(int i = 0; i <= a; i++){
            if(b-2*i>=0){
                int x = a-i;
                int y = b-2*i;
                int cnt = min(y,c/2);
                ans=max(ans,i+2*i+cnt*3);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}