#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define pii pair<int,int>
#define pll pair<ll,ll>
const int maxn=100000+10;
const ll mod=1e9+7;
ll f[maxn];
char s[maxn];
int main()
{
    f[0]=f[1]=1;
    for(int i=2;i<maxn;i++){
        f[i]=(f[i-1]+f[i-2])%mod;
    }
    cin>>s;
    int l=strlen(s);
    ll ans=1;
    int cntu=0,cntv=0;
    for(int i=0;i<l;i++)
    {
        if(s[i]=='m'||s[i]=='w') ans=0;
        if(s[i]=='u')
            cntu++;
        else{
            ans=ans*f[cntu]%mod;
            cntu=0;
        }
        if(s[i]=='n')
            cntv++;
        else{
            ans=ans*f[cntv]%mod;
            cntv=0;
        }
    }
    if(cntu!=0) ans=ans*f[cntu]%mod;
    if(cntv!=0) ans=ans*f[cntv]%mod;
    cout<<ans<<endl;
    return 0;
}
