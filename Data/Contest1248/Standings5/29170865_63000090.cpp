#include <bits/stdc++.h>
#define ll long long
#define forin for(int i=0;i<n;i++)
#define forim for(int i=0;i<m;i++)
#define forjn for(int j=0;j<n;j++)
#define forjm for(int j=0;j<m;j++)
using namespace std;
ll sm[100010][2][2],sm2[100010][2][2],e=1000000007;
ll cnt(ll n,ll a,ll b,ll i){
    if(i>=n-1)
        return 1;
    if(sm[i][a][b])
        return sm[i][a][b];
    ll sum=0;
    if(a==1&&b==1){
        sum+=cnt(n,1,0,i+1);
    }
    else if(a==0&&b==0){
        sum+=cnt(n,0,1,i+1);
    }
    else{
        sum+=cnt(n,b,b,i+1)+cnt(n,b,a,i+1);
    }
    return sm[i][a][b]=sum%e;
}
ll cnt2(ll n,ll a,ll b,ll i){
    if(i>=n-1)
        return 1;
    if(sm2[i][a][b])
        return sm2[i][a][b];
    ll sum=0;
    if(a==1&&b==1){
        sum+=cnt2(n,1,0,i+1);
    }
    else if(a==0&&b==0){
        sum+=cnt2(n,0,1,i+1);
    }
    else{
        sum+=cnt2(n,b,b,i+1)+cnt2(n,b,a,i+1);
    }
    return sm2[i][a][b]=sum%e;
}
int main()
{
    ll n,m;
    cin>>n>>m;
    if(n<m)
        swap(n,m);
    if(n==1&&m==1){
        cout<<2;
        return 0;
    }
    if(m==1){
        ll sum1=cnt(n,0,1,1)+cnt(n,1,1,1)+cnt(n,1,0,1)+cnt(n,0,0,1);
        cout<<sum1%e;
        return 0;
    }
    ll sum1=cnt(n,0,1,1)+cnt(n,1,1,1)+cnt(n,1,0,1)+cnt(n,0,0,1),sum2=cnt2(m,0,1,1)+cnt2(m,1,1,1)+cnt2(m,1,0,1)+cnt2(m,0,0,1);
    cout<<(sum1+sum2-2+e)%e;
    return 0;
}
