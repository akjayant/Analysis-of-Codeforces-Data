//
#include<iostream>
#include<cstring>
using namespace std;
#define ll long long
#define mod 1000000007
#define maxnn 200010
string s1;
ll f1[maxnn],f2[maxnn];
ll feb[maxnn];
int main()
{
    feb[1]=1;
    feb[0]=1;
    for(int i=1;i<=1e5+10;i++)
    {
        feb[i]=(feb[i-1]+feb[i-2])%mod;
    }
    cin>>s1;
    ll ans1=1;
    ll ans2=1;
    
    ll d=s1.size();
    for(int i=0;i<d;i++)
    {
        if(s1[i]=='m'||s1[i]=='w')
        {
            puts("0");
            return 0;
        }
    }
    for(int i=0;i<d;i++)
    {
        if(s1[i]=='u')
        {
            f1[i]=f1[max(0,i-1)]+1;
            if(f1[i]<=1) continue;
            if(i==(d-1))
            {
                ans1=(ans1*feb[f1[i]])%mod;
                continue;
            }
            if(s1[i+1]!='u')
            {
                ans1=(ans1*feb[f1[i]])%mod;
                continue;
            }
            
        }
        else{
            f1[i]=0;
        }
    }
    for(int i=0;i<d;i++)
    {
        if(s1[i]=='n')
        {
            f2[i]=f2[max(0,i-1)]+1;
            if(f2[i]<=1) continue;
            if(i==(d-1))
            {
                ans1=(ans1*feb[f2[i]])%mod;
                continue;
            }
            if(s1[i+1]!='n')
            {
                ans1=(ans1*feb[f2[i]])%mod;
                continue;
            }
        }
        else{
            f2[i]=0;
        }
    }
    cout<<(ans1*ans2)%mod;
}
