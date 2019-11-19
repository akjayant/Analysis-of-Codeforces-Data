#pragma GCC optimize ("2")
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int ll
typedef pair<int,int> pr;
const int mxn = 3e5+5;
const int mxm = 3e5+5 ;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-7;
const double pii = 3.1415926535898;
#define mpr make_pair
int gcd(int x,int y){if(y==0) return x; else return gcd(y,x%y);}
int qpow(int a,int b){int ans=1; while(b){ if(b&1) ans=ans*a%mod; b>>=1; a=a*a%mod; } return ans;}
int lowbit(int x){return (x&(-x));}
int qmul(int a,int b){int ans=0; while(b){ if(b&1) ans=(ans+a)%mod; b>>=1; a=(a+a)%mod; } return ans; }
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int a[mxn],b[mxn];
signed main(void){
    int t;
    scanf("%lld",&t);
    while(t--){
        int n,m;
        scanf("%lld",&n);
        int ct0=0,ct1=0;
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            if(a[i]%2==0)ct0++;
            else ct1++;
        }
        scanf("%lld",&m);
        for(int i=1;i<=m;i++)scanf("%lld",&b[i]);
        int res = 0;
        for(int i=1;i<=m;i++){
            if(b[i]%2==0){
                res+=ct0;
            }
            else{
                res+=ct1;
            }
        }
        printf("%lld\n",res);
    }
}
