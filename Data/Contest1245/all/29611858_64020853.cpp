#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
const int MAXN = 3e5+5;
const int MOD = 1e9+7;
char s[MAXN];
const int maxn=1e6+10;
const int mod=1e9+7;
ll fac[maxn],f[maxn],inv[maxn];

void init()
{
    fac[0]=fac[1]=f[0]=f[1]=inv[0]=inv[1]=1;
    for(int i=2;i<maxn;i++)
    {
        fac[i]=fac[i-1]*i%mod;   // n！
        ll t=mod/i,k=mod%i;
        f[i]=(mod-t)*f[k]%mod;  // n的逆元
        inv[i]=inv[i-1]*f[i]%mod; // n！的逆元
    }
}

ll C(ll n,ll m)
{
    if(n<m) return 0;
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
ll suan(ll x){
    ll temp=0;
    for(int i=0;2*i<=x;i++){
        temp+=C(i+x-2*i,x-2*i);
        temp%=MOD;
    }
    return temp;
}
int main()
{
    init();
    while(~scanf("%s",s)){
        int len=strlen(s);
        int flag=0;
        rep(i,0,len-1){
            if(s[i]=='m'||s[i]=='w'){
                flag=1;
                break;
            }
        }
        if(flag){
            puts("0");
            continue;
        }
        int num=0;
        ll ans=1;
        rep(i,0,len-1){
            if(s[i]=='u'){
                if(i&&s[i-1]!='u'){
                    if(num>=2){
                        ans*=suan(num);
                        ans%=MOD;
                    }
                    num=0;
                }
                num++;
            }
            else if(s[i]=='n'){
                if(i&&s[i-1]!='n'){
                    if(num>=2){
                        ans*=suan(num);
                        ans%=MOD;
                    }
                    num=0;
                }
                num++;
            }
            else{
                if(num>=2){
                    ans*=suan(num);
                    ans%=MOD;
                }num=0;
            }
        }

        if(num>=2){
            ans*=suan(num);
            ans%=MOD;
        }
        cout<<ans<<endl;
    }
    return 0;
}
