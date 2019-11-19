#include <cstdio>
#include <algorithm>
using namespace std;
#define N 200005
#define ll long long
int n; ll a[N]; ll mn; ll mx; ll k;
int ltag; int rtag;


int main(){
    scanf("%d %lld",&n,&k);
    for(int i=1;i<=n;++i) scanf("%lld",a+i);
    sort(a+1,a+1+n);  ltag=1; rtag=n; mn=a[1]; mx=a[n];
    for(int i=2;i<=n;++i){
        if(a[i]==a[i-1]) ltag=i;
        else             break;
    }
    for(int i=n-1;i>=1;--i){
        if(a[i]==a[i+1]) rtag=i;
        else             break;
    }
    if(ltag>=rtag){
        printf("0\n");
        return 0;
    }
    else{
        while(ltag<rtag){
            int lnum=ltag; //上升左边答案-1需要花费lnum的代价
            int rnum=n-rtag+1; //下降右边答案-1需要花费rnum的代价
            if(lnum<rnum){  // 上升的代价小 自然是上升
                ll up_times=min(k/lnum,a[ltag+1]-a[ltag]);
                mn+=up_times;
                if(mn!=a[ltag+1]){
                    printf("%lld\n",mx-mn);
                    return 0;
                }
                k-=up_times*lnum;
                int new_ltag=ltag+1; ltag=ltag+1;
                for(int i=new_ltag+1;i<=n;++i){
                    if(a[i]==a[i-1]) ltag=i;
                    else break;
                }
                if(ltag>=rtag){
                    printf("%lld\n",mx-mn);
                    return 0;
                }
            }
            else{
                ll down_times=min(k/rnum,a[rtag]-a[rtag-1]);
                mx-=down_times;
                if(mx!=a[rtag-1]){
                    printf("%lld\n",mx-mn);
                    return 0;
                }
                k-=down_times*rnum;
                int new_rtag=rtag-1; rtag=rtag-1;
                for(int i=new_rtag-1;i>=1;--i){
                    if(a[i]==a[i+1]) rtag=i;
                    else  break;
                }
                if(ltag>=rtag){
                    printf("%lld\n",mx-mn);
                    return 0;
                }
            }
        }
    }
    return 0;
    
}














