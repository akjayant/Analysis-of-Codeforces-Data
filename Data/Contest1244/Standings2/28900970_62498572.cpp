#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int ll
typedef pair<int,int> pr;
const int mxn = 2e5+5;
const int mxm = 1;
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

int a[mxn];
int pp[mxn],cc[mxn];
signed main(void){
    int n,k;
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    int ans = a[n] - a[1];
    int lec = 1,ric  = 1,lepos = 1,ripos = n;
//    for(int i=1;i<=n;i++){
//        printf("i=%lld,a[i]=%lld\n",i,a[i]);
//    }
    while(k){
        if(lepos>=ripos)break;

        if(lec<=ric){
            int shu = a[lepos+1]-a[lepos];
            if(shu * lec>k){
                ans = ans - k/lec;
                break;
            }
            else{
                ans = ans - shu;
                k-=shu * lec;
                lepos++;
                lec++;
//                printf("shu=%lld,lepos=%lld,ripos=%lld,lec=%lld,ric=%lld,k=%lld,ans=%lld\n",shu,lepos,ripos,lec,ric,k,ans);
            }
        }
        else{
            int shu = a[ripos] - a[ripos-1];
            if(shu * ric>k){
                ans = ans - k/ric;
                break;
            }
            else{
                ans = ans - shu;
                k-=shu * ric;
                ric++;
                ripos--;
//                printf("shu=%lld,lepos=%lld,ripos=%lld,lec=%lld,ric=%lld,k=%lld,ans=%lld\n",shu,lepos,ripos,lec,ric,k,ans);
            }
        }
//        printf("lepos=%lld,ripos=%lld,ans=%lld\n",lepos,ripos,ans);
    }
    printf("%lld\n",ans);
}
