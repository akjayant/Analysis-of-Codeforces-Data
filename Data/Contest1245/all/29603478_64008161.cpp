#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+10,mod=1e9+7;
string s;
ll f[N];
int main()
{
  //  freopen("i.txt","r",stdin);
    ll as=1;
    cin>>s;
    f[1]=1;
    f[2]=2,f[3]=3;
    for(int i=4; i<N; i++)f[i]=(f[i-1]+f[i-2])%mod;
    int n=s.length();
    for(int i=0; i<n; i++)
        if(s[i]=='m'||s[i]=='w')
        {
            puts("0");
            return 0;
        }
    for(int i=0; i<n; i++)
    {
        if(s[i]=='u')
        {
            int j=i;
            while(j<n&&s[j]=='u')j++;
            as=as*f[j-i]%mod;
           // cout<<i<<' '<<j-i+1<<
            i=j-1;
        }
        if(s[i]=='n')
        {
            int j=i;
            while(j<n&&s[j]=='n')j++;
            as=as*f[j-i]%mod;
            i=j-1;
        }
    }
    printf("%lld\n",as);
}
