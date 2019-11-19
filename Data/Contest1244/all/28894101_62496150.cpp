#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define ss second
#define ff first
using namespace std;
int n;
ll k,a[100010];
int main(){

    //freopen("test.txt","r",stdin);

    scanf("%d %lld",&n,&k);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);

    ll minn=a[1];
    ll maxx=a[n];

    int l=1;
    int r=n;
    while(1){

       if(minn==maxx)break;

       while(minn==a[l+1])l++;
       while(maxx==a[r-1])r--;

       ll lcost=l;
       ll rcost=n-r+1;

       if(lcost<rcost){
        ll hm=min(a[l+1]-minn,k/lcost);
        if(hm==0)break;
        k-=hm*lcost;
        minn+=hm;
       }
       else{
        ll hm=min(maxx-a[r-1],k/rcost);
        if(hm==0)break;
        k-=hm*rcost;
        maxx-=hm;
       }

    }

    printf("%lld\n",maxx-minn);

    return 0;
}

