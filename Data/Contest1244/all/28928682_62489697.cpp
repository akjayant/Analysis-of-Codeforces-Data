#include<bits/stdc++.h>
using namespace std;
#define maxn 100008
#define int long long
int n,k;
int a[maxn];
signed main(){
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    int minnum=0,maxnum=0;
    int minval=a[1],maxval=a[n];
    int l=0,r=n+1;
    for(int i=1;i<=n;i++){
        if(a[i]==a[1])minnum++,l++;
        else break;
    }
    for(int i=n;i>=1;i--){
        if(a[i]==a[n])maxnum++,r--;
        else break;
    }
    while(l<r&&k>0){
        bool flag=0;
        if(minnum<maxnum){
            int num=minnum*(a[l+1]-a[l]);
            if(k>=num){
                flag=1;
                k-=num;
                l++;minnum++;
                while(a[l+1]==a[l]){
                    minnum++,l++;
                }
            }
        }else{
            int num=maxnum*(a[r]-a[r-1]);
            if(k>=num){
                flag=1;
                k-=num;
                r--;maxnum++;
                while(a[r-1]==a[r]){
                    r--;maxnum++;
                }
            }
        }
        if(!flag)break;
    }
    cout<<max(a[r]-a[l]-k/min(minnum,maxnum),0ll)<<endl;
    return 0;
}