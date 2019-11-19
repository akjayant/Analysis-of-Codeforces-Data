
#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int n,p,w,d;
    cin>>n>>p>>w>>d;
    int gcd=__gcd(w,d);
    if(p%gcd){puts("-1");return 0;}
    p/=gcd;w/=gcd;d/=gcd;
    int ans1=0;bool flag=0;
    while(ans1<=n){
        if(w*ans1>p){flag=1;break;}
        if(!((p-w*ans1)%d))break;
        ans1++;
    }//write(ans1);
    if(flag){puts("-1");return 0;}
    int ans2=(p-w*ans1)/d;
    if(d<w){int tmp=ans2/w;ans1+=d*tmp;ans2-=w*tmp;}
    if(ans1+ans2>n){puts("-1");return 0;}
    cout<<ans1<<" "<<ans2<<" "<<n-ans1-ans2<<endl;;
    return 0;
}
