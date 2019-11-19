#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>

#define fuck(x) cerr<<#x<<" = "<<x<<endl;
#define debug(a, x) cerr<<#a<<"["<<x<<"] = "<<a[x]<<endl;
#define lson l,mid,ls
#define rson mid+1,r,rs
#define ls (rt<<1)
#define rs ((rt<<1)+1)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int loveisblue = 486;
const int maxn = 200086;
const int maxm = 200086;
const int inf = 0x3f3f3f3f;
const ll Inf = 999999999999999999;
const int mod = 1000000007;
const double eps = 1e-6;
const double pi = acos(-1);

int main() {
    ios::sync_with_stdio(true);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    int T;
    scanf("%d",&T);
    while(T--){
        int a,b,c,d,k;
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        int t1 = a/c;
        int t2 = b/d ;
        if(a%c){
            t1++;
        }if(b%d){
            t2++;
        }
        if(t1+t2>k){
            printf("-1\n");
        }else{
            printf("%d %d\n",t1,t2);
        }
    }

    return 0;
}
