#define HAVE_STRUCT_TIMESPEC
#include<bits/stdc++.h>
using namespace std;
int a[100007];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    long long k;
    cin>>n>>k;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+1+n);
    long long mostsmall=a[1];
    long long mostbig=a[n];
    while(k>=0){
        if(mostsmall>=mostbig){
            cout<<0;
            return 0;
        }
        int flag1=upper_bound(a+1,a+1+n,mostsmall)-a;
        int flag2=lower_bound(a+1,a+1+n,mostbig)-a;
        flag1=flag1-1;
        if(flag1>=n+1-flag2){
            long long x=k/(n+1-flag2);
            if(!x)
                break;
            k-=(n+1-flag2)*min(x,mostbig-a[flag2-1]);
            mostbig-=min(x,mostbig-a[flag2-1]);
        }
        else{
            long long x=k/flag1;
            if(!x)
                break;
            k-=flag1*min(x,a[flag1+1]-mostsmall);
            mostsmall+=min(x,a[flag1+1]-mostsmall);
        }
    }
    long long ans=0;
    ans=mostbig-mostsmall;
    cout<<max(0ll,ans);
    return 0;
}
