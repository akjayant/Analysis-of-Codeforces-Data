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

ll f[maxn];
char a[maxn];
int main(){
    f[0]=f[1]=1;
    for(int i = 2; i <= 100000+100; i++){
        f[i]=(f[i-1]+f[i-2])%mod;
    }
    scanf("%s",a+1);
    int n = strlen(a+1);
    int ok = 1;
    ll ans = 1;
    int tmp = 0;
    for(int i = 1; i <= n; i++){
        if(a[i]=='m'||a[i]=='w')ok=0;
        if(a[i]=='n'){
            tmp++;
        }
        else{
            ans=ans*f[tmp]%mod;
            tmp=0;
        }
    }
    ans=ans*f[tmp]%mod;
    tmp=0;
    for(int i = 1; i <= n; i++){
        if(a[i]=='u'){
            tmp++;
        }
        else{
            ans=ans*f[tmp]%mod;
            tmp=0;
        }
    }
    ans=ans*f[tmp]%mod;
    if(!ok){
        printf("0");
    }
    else{
        printf("%lld",ans);
    }



    return 0;
}
/*

*/
