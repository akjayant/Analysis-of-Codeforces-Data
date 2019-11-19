#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[1005];
int a1[1005];
int a2[1005];
int sum[1005];
int minn1[1005];
int minn2[1005];
int n;
int work()
{
    int ans=0;
    sum[0]=0;
    for(int i=1;i<=n;i++){
        if(a[i]=='('){
            sum[i]=sum[i-1]+1;
        }else{
            sum[i]=sum[i-1]-1;
        }
    }
    minn1[1]=sum[1];
    for(int i=2;i<=n;i++){
        minn1[i]=min(minn1[i-1],sum[i]);
    }
    minn2[n]=sum[n];
    for(int i=n-1;i>=1;i--){
        minn2[i]=min(minn2[i+1],sum[i]);
    }
    for(int i=0;i<=n-1;i++){
        if((minn2[i+1]-sum[i]>=0)&&(minn1[i]+sum[n]-sum[i]>=0))ans++;
    }
    return ans;
}
int main()
{
    scanf("%d",&n);
    scanf("%s",a+1);
    int cnt1=0;
    int cnt2=0;
    for(int i=1;i<=n;i++){
        if(a[i]=='('){
            a1[cnt1++]=i;
        }else{
            a2[cnt2++]=i;
        }
    }
    if(cnt1!=cnt2){
        printf("0\n1 1\n");
        return 0;
    }
    int ans=work();
    int ans1=1;
    int ans2=1;
    for(int i=0;i<cnt1;i++){
        for(int j=0;j<cnt2;j++){
            swap(a[a1[i]],a[a2[j]]);
            int tmp=work();
            if(tmp>ans){
                ans=tmp;
                ans1=a1[i];
                ans2=a2[j];
            }
            swap(a[a1[i]],a[a2[j]]);
        }
    }
    printf("%d %d %d\n",ans,ans1,ans2);
}