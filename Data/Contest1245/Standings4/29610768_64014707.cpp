#include "bits/stdc++.h"
using namespace std;
#define int int64_t
#define mp make_pair
#define f first
#define s second
#define mod 1000*1000*1000+7
int power(int x, int y, int p)
{
    int res = 1;      // Initialize result
    
    x = x % p;  // Update x if it is more than or
    // equal to p
    
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
        
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string ss;cin>>ss;
    int fac[1<<17];
    fac[0]=1;
    for(int i=1;i<=1e5;i++)
    {
        fac[i]=fac[i-1]*i;
        fac[i]%=mod;
    }
    if(ss.find('m')<=ss.length()||ss.find('w')<=ss.length())
    {
        cout<<"0\n";
    }
    else
    {
        int ans=1;
        for(int i=0;i<ss.length();i++)
        {
            if(ss[i]=='u')
            {
                int tans=0;
                int count=0;
                while(ss[i]=='u')
                {
                    count++;
                    i++;
                }
                for(int i=0;count-2*i>=0;i++)
                {
                    int kk=fac[count-i];
                    kk%=mod;
                    kk*=power(fac[i],mod-2,mod);
                    kk%=mod;
                    kk*=power(fac[count-i-i],mod-2,mod);
                    kk%=mod;
                    tans+=kk;
                    tans%=mod;
                }
                ans*=tans;
                ans%=mod;
                i--;
            }
            else if(ss[i]=='n')
            {
                int count=0;
                int tans=0;
                while(ss[i]=='n')
                {
                    count++;
                    i++;
                }
                for(int i=0;count-2*i>=0;i++)
                {
                    int kk=fac[count-i];
                    kk%=mod;
                    kk*=power(fac[i],mod-2,mod);
                    kk%=mod;
                    kk*=power(fac[count-i-i],mod-2,mod);
                    kk%=mod;
                    tans+=kk;
                    tans%=mod;
                }
                ans*=tans;
                ans%=mod;
                i--;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
