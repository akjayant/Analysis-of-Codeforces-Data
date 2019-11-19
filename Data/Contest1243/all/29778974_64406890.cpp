#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll n,a[N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    int cnt=0;
    for(int i=2;1LL*i*i<=n;i++)
        if(n%i==0){
            a[++cnt]=i;
            while(n%i==0)n/=i;
        }
    if(n!=1)a[++cnt]=n;
    int bj1=0,bj2=0;
    for(ll i=1;i<=cnt;i++)
    {
        if(a[i]%2==0)bj1=1;
        else bj2=1;
    }
    ll ans;
    if(bj1==0&&bj2==0)ans=n;
    else if(bj1==1&&bj2==1)ans=1;
    else if(bj1==1&&bj2==0)ans=2;
    else if(bj1==0&&bj2==1&&cnt==1)ans=a[1];
    else if(bj1==0&&bj2==1&&cnt>1)ans=1;
    cout<<ans<<"\n";
    return 0;
}
